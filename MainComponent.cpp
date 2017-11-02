#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <random>
#include <iostream>




class MainContentComponent   : public AudioAppComponent,
                               public ChangeListener,
                               public Button::Listener


{
public:
MainContentComponent()
:   state (Stopped)
{


        
        addAndMakeVisible (&playButton);
        playButton.setButtonText ("Play");
        playButton.addListener (this);
        playButton.setColour (TextButton::buttonColourId, Colours::green);
        playButton.setEnabled (true);

   
        setSize (300, 200);
        
        formatManager.registerBasicFormats();       // [1]
        transportSource.addChangeListener (this);   // [2]

        setAudioChannels (0, 2);
    }
    
    ~MainContentComponent()
    {
        shutdownAudio();
    }

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        transportSource.prepareToPlay (samplesPerBlockExpected, sampleRate);
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        if (readerSource == nullptr)
        {
            bufferToFill.clearActiveBufferRegion();
            return;
        }
        
        transportSource.getNextAudioBlock (bufferToFill);
    }

    void releaseResources() override
    {
        transportSource.releaseResources();
    }

    void resized() override
    {

        playButton.setBounds (10, 40, getWidth() - 20, 20);

    }
    
    void changeListenerCallback (ChangeBroadcaster* source) override
    {
        if (source == &transportSource)
        {
            if (transportSource.isPlaying())
                changeState (Playing);
            else
                changeState (Stopped);
        }
    }

    void buttonClicked (Button* button) override
    {

        if (button == &playButton)  playButtonClicked();

    }

private:
    enum TransportState
    {
        Initial,
        Stopped,
        Starting,
        Playing,
        Finished
    };
    
    void changeState (TransportState newState)
    {
        if (state != newState)
        {
            state = newState;
            
            switch (state)
            {
                
                case Initial:
                    
                    transportSource.setPosition (0.0);
                    filesPlayed = 0;
                    break;
                    
                    
                case Stopped:                           // [3]

                    filesPlayed ++;
                    if (filesPlayed == 1)
                    {

                        int choice2 = Random::getSystemRandom().nextInt(2);
                        playfile(choice2);
                    }
                    
                    
                
                    break;
                    
                case Starting:                          // [4]
                    playButton.setEnabled (true);
                    transportSource.start();
                    break;
                    
                case Playing:                           // [5]
 //                   stopButton.setEnabled (true);
                    break;
                    
                case Finished:
                    playButton.setEnabled (true);// [6]
                    transportSource.stop();
                    transportSource.setPosition (0.0);
                    break;
            }
        }
    }
    

        
            

    void playfile(int n)
    {
        AudioFormatReader* reader = formatManager.createReaderFor( new MemoryInputStream(BinaryData::getNamedResource(BinaryData::namedResourceList[n], mp3Size), mp3Size, false));
        if (reader != nullptr)
        {
            ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource (reader, true);
            transportSource.setSource (newSource, 0, nullptr, reader->sampleRate);
            playButton.setEnabled (true);
            readerSource = newSource.release();
        }
        if (reader == nullptr)
        {
            playButton.setEnabled (false);
        }
        transportSource.setPosition (0.0);
        changeState (Starting);
    }
    
 
    
    void playButtonClicked()
    {

        int choice1 = Random::getSystemRandom().nextInt(2);


        playfile(choice1);
    }
    
        

        


        

        
    
    
    
    
/*    void stopButtonClicked()
    {
        changeState (Stopping);
    }
*/
    
    //==========================================================================
//    TextButton openButton;
    TextButton playButton;
//    TextButton stopButton;
    
    AudioFormatManager formatManager;
    ScopedPointer<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    TransportState state;
    char* note;
    char* newnote;

    int filesPlayed = 0;
    int f;
    int mp3Size = 93546;
    
 //   Range::range<int> range(const int 0,const int 1);
  

    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
