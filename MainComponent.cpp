#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <random>
#include <iostream>
#include <vector>




class MainContentComponent   : public AudioAppComponent,
                               //public Component,
                               public ChangeListener,
                               //public Slider::Listener,

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
    
    
        addAndMakeVisible (&noteButton);
        noteButton.setButtonText ("play 4 notes");
        noteButton.addListener (this);
        noteButton.setColour (TextButton::buttonColourId, Colours::red);
        noteButton.setEnabled (true);
    
        addAndMakeVisible (&eightNoteButton);
        eightNoteButton.setButtonText ("play 8 notes");
        eightNoteButton.addListener (this);
        eightNoteButton.setColour (TextButton::buttonColourId, Colours::red);
        eightNoteButton.setEnabled (true);
    
        addAndMakeVisible (&oneOctaveButton);
        oneOctaveButton.setButtonText ("one octave only");
        oneOctaveButton.addListener (this);
        oneOctaveButton.setColour (TextButton::buttonColourId, Colours::red);
        oneOctaveButton.setEnabled (true);
    
        addAndMakeVisible (&includeCButton);
        includeCButton.setButtonText ("Include C");
        includeCButton.addListener (this);
        includeCButton.setColour (TextButton::buttonColourId, Colours::lightblue);
        includeCButton.setEnabled (true);
    
        addAndMakeVisible (&includeCsharpButton);
        includeCsharpButton.setButtonText ("Include C#");
        includeCsharpButton.addListener (this);
        includeCsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        includeCsharpButton.setEnabled (true);
    
        addAndMakeVisible (&includeDButton);
        includeDButton.setButtonText ("Include D");
        includeDButton.addListener (this);
        includeDButton.setColour (TextButton::buttonColourId, Colours::lightblue);
        includeDButton.setEnabled (true);
    
        addAndMakeVisible (&includeDsharpButton);
        includeDsharpButton.setButtonText ("Include D#");
        includeDsharpButton.addListener (this);
        includeDsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        includeDsharpButton.setEnabled (true);
    
        addAndMakeVisible (&includeEButton);
        includeEButton.setButtonText ("Include E");
        includeEButton.addListener (this);
        includeEButton.setColour (TextButton::buttonColourId, Colours::lightblue);
        includeEButton.setEnabled (true);
    
        addAndMakeVisible (&includeFButton);
        includeFButton.setButtonText ("Include F");
        includeFButton.addListener (this);
        includeFButton.setColour (TextButton::buttonColourId, Colours::lightblue);
        includeFButton.setEnabled (true);
    
        addAndMakeVisible (&includeFsharpButton);
        includeFsharpButton.setButtonText ("Include F#");
        includeFsharpButton.addListener (this);
        includeFsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        includeFsharpButton.setEnabled (true);
    
        addAndMakeVisible (&includeGButton);
        includeGButton.setButtonText ("Include G");
        includeGButton.addListener (this);
        includeGButton.setColour (TextButton::buttonColourId, Colours::lightblue);
        includeGButton.setEnabled (true);
    
        addAndMakeVisible (&includeGsharpButton);
        includeGsharpButton.setButtonText ("Include G#");
        includeGsharpButton.addListener (this);
        includeGsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        includeGsharpButton.setEnabled (true);
    
        addAndMakeVisible (&includeAButton);
        includeAButton.setButtonText ("Include A");
        includeAButton.addListener (this);
        includeAButton.setColour (TextButton::buttonColourId, Colours::lightblue);
        includeAButton.setEnabled (true);
    
        addAndMakeVisible (&includeAsharpButton);
        includeAsharpButton.setButtonText ("Include A#");
        includeAsharpButton.addListener (this);
        includeAsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        includeAsharpButton.setEnabled (true);
    
        addAndMakeVisible (&includeBButton);
        includeBButton.setButtonText ("Include B");
        includeBButton.addListener (this);
        includeBButton.setColour (TextButton::buttonColourId, Colours::lightblue);
        includeBButton.setEnabled (true);
    
        addAndMakeVisible (&resetButton);
        resetButton.setButtonText ("reset");
        resetButton.addListener (this);
        resetButton.setColour (TextButton::buttonColourId, Colours::orange);
        resetButton.setEnabled (true);

        setSize (600, 600);

    
        formatManager.registerBasicFormats();       // [1]
        transportSource.addChangeListener (this);   

        setAudioChannels (0, 2);
    }
    
    ~MainContentComponent()
    {
        shutdownAudio();
    }
    
//    void MainComponent::paint (Graphics& g)
//    {
//        g.fillAll (Colours::lightblue);
//        g.setColour (Colours::darkblue);
//        g.setFont (20.0f);

//    }

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
        noteButton.setBounds (10, 70, getWidth() - 20, 20);
        eightNoteButton.setBounds (10, 100, getWidth() - 20, 20);
        oneOctaveButton.setBounds (10, 130, getWidth() - 20, 20);
        includeCButton.setBounds (10, 160, getWidth() - 20, 20);
        includeCsharpButton.setBounds (10, 190, getWidth() - 20, 20);
        includeDButton.setBounds (10, 220, getWidth() - 20, 20);
        includeDsharpButton.setBounds (10, 250, getWidth() - 20, 20);
        includeEButton.setBounds (10, 280, getWidth() - 20, 20);
        includeFButton.setBounds (10, 310, getWidth() - 20, 20);
        includeFsharpButton.setBounds (10, 340, getWidth() - 20, 20);
        includeGButton.setBounds (10, 370, getWidth() - 20, 20);
        includeGsharpButton.setBounds (10, 400, getWidth() - 20, 20);
        includeAButton.setBounds (10, 430, getWidth() - 20, 20);
        includeAsharpButton.setBounds (10, 460, getWidth() - 20, 20);
        includeBButton.setBounds (10, 490, getWidth() - 20, 20);
        resetButton.setBounds (10, 520, getWidth() - 20, 20);

    }
    
//    void paint() override
//    {
//       g.fillAll (Colours::lightblue);
//    }
    
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
        if (button == &noteButton)  noteButtonClicked();
        if (button == &eightNoteButton)  eightnoteButtonClicked();
        if (button == &oneOctaveButton)  oneOctaveButtonClicked();
        if (button == &includeCButton)  includeCButtonClicked();
        if (button == &includeCsharpButton)  includeCsharpButtonClicked();
        if (button == &includeDButton)  includeDButtonClicked();
        if (button == &includeDsharpButton)  includeDsharpButtonClicked();
        if (button == &includeEButton)  includeEButtonClicked();
        if (button == &includeFButton)  includeFButtonClicked();
        if (button == &includeFsharpButton)  includeFsharpButtonClicked();
        if (button == &includeGButton)  includeGButtonClicked();
        if (button == &includeGsharpButton)  includeGsharpButtonClicked();
        if (button == &includeAButton)  includeAButtonClicked();
        if (button == &includeAsharpButton)  includeAsharpButtonClicked();
        if (button == &includeBButton)  includeBButtonClicked();
        if (button == &resetButton)  resetButtonClicked();
        
        
    

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
                    for (int h=0; h < 12; h++)
                    {
                        numbers[h] = 0;
                    }
                    s=0;
                    found =0;
                    
                    ss =0;
                    i=0;
                    ssa =0;
                    sa =0;
                    transportSource.setPosition (0.0);
                    myvector.clear();
                    myvector.empty();
                    myvector.clear();
                    myvector.empty();
                    break;
                    
                case Stopped:
                    filesPlayed ++;
                    if (filesPlayed <numNotes)
                    {
                        sa = myvector.size();
                        ssa = int(sa);

                        int choice2 = Random::getSystemRandom().nextInt(ssa);

                        int octavechoice2 = Random::getSystemRandom().nextInt(2);
                        if (octaveRange == 1)
                        {
                            oct = 0;
                        }
                        if (octaveRange == 2)
                        {
                            oct = octavechoice2;
                        }
                        
                        
                        
                        int g = myvector.at(choice2);
                        noteToPlay = g + (oct*12)   ;
                        
                        playfile(noteToPlay);
                    }
                    break;
                case Starting:
                    playButton.setEnabled (true);
                    transportSource.start();
                    break;
                case Playing:
                    break;
                case Finished:
                    playButton.setEnabled (true);
                    transportSource.stop();
                    transportSource.setPosition (0.0);
                    break;
            }
        }
    }
    // edited version of play file demo
    // I have a bunch of mp3 files loaded as binary resources
    // I used the named resource[] to select them and play them in this method
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
    // this code is what is crashing the plugin
    // ###THIS WOULD WORK #####
    // int choice2 = Random::getSystemRandom().nextInt(35);
    // playfile(choice2);
    // ### i am trying to replace it with this //
    void playButtonClicked()
    {
        myvector.clear();
        myvector.empty();
    // I am not sure where this for loop should be located and
     //   if the variables are correctly in scope
        for (int i=0; i < 12; i++)
        {
            if (numbers[i] == 1)
            {
                myvector.push_back(i);
                found = 1;
            }
        }
        
        if (found == 0)
        {
            changeState(Initial);
            
        }
    // select a random number and than grap an index from my vector
        else
        {
            s = myvector.size();
            ss = int(s);
            choice = Random::getSystemRandom().nextInt(ss);
            int octavechoice = Random::getSystemRandom().nextInt(2);
            if (octaveRange == 1)
            {
            oct = 0;
            }
            if (octaveRange == 2)
            {
            oct = octavechoice;
            }
            int f = myvector.at(choice);
            noteToPlay = f + (oct*12);
            playfile(noteToPlay);
        }
    }
    void noteButtonClicked()
    {
        if (notesButtonpressed == 0)
        {
            numNotes = 4;
            noteButton.setEnabled (false);
            notesButtonpressed = 1;
        }
        else
        {
            numNotes = 2;
            noteButton.setEnabled (true);
            notesButtonpressed = 1;
        }
    }
    void eightnoteButtonClicked()
    {
        if (eightNoteButtonpressed == 0)
        {
            numNotes = 8;
            eightNoteButton.setEnabled (false);
            eightNoteButtonpressed = 1;
        }
        else
        {
        
            numNotes = 2;
            eightNoteButton.setEnabled (true);
            eightNoteButtonpressed = 1;
        }
    }
    
    void oneOctaveButtonClicked()
    {
        if (oneOctaveButtonpressed == 0)
        {
            octaveRange = 1;
            oneOctaveButton.setEnabled (false);
            oneOctaveButtonpressed = 1;
        }
        else
        {
            
            octaveRange = 2;
            oneOctaveButton.setEnabled (true);
            oneOctaveButtonpressed = 1;
        }
    }
    void includeCButtonClicked()
    {
        if (includeCButtonpressed == 0)
        {
            numbers[0] = 1;
            includeCButton.setEnabled (false);
            includeCButtonpressed = 1;
        }
        else
        {
        
            numbers[0] = 0;
            includeCButton.setEnabled (true);
            includeCButtonpressed = 0;
        }
    }
    void includeCsharpButtonClicked()
    {
        if (includeCsharpButtonpressed == 0)
        {
            numbers[1] = 1;
            includeCsharpButton.setEnabled (false);
            includeCsharpButtonpressed = 1;
        }
        else
        {
            
            numbers[1] = 0;
            includeCsharpButton.setEnabled (true);
            includeCsharpButtonpressed = 0;
        }
    }
    void includeDButtonClicked()
    {
        if (includeDButtonpressed == 0)
        {
            numbers[2] = 1;
            includeDButton.setEnabled (false);
            includeDButtonpressed = 1;
        }
        else
        {
            
            numbers[2] = 0;
            includeDButton.setEnabled (true);
            includeDButtonpressed = 0;
        }
    }

    void includeDsharpButtonClicked()
    {
        if (includeDsharpButtonpressed == 0)
        {
            numbers[3] = 1;
            includeDsharpButton.setEnabled (false);
            includeDsharpButtonpressed = 1;
        }
        else
        {
            
            numbers[3] = 0;
            includeDsharpButton.setEnabled (true);
            includeDsharpButtonpressed = 0;
        }
    }
    void includeEButtonClicked()
    {
        if (includeEButtonpressed == 0)
        {
            numbers[4] = 1;
            includeEButton.setEnabled (false);
            includeEButtonpressed = 1;
        }
        else
        {
            
            numbers[4] = 0;
            includeEButton.setEnabled (true);
            includeEButtonpressed = 0;
        }
    }
    void includeFButtonClicked()
    {
        if (includeFButtonpressed == 0)
        {
            numbers[5] = 1;
            includeFButton.setEnabled (false);
            includeFButtonpressed = 1;
        }
        else
        {
            
            numbers[5] = 0;
            includeFButton.setEnabled (true);
            includeFButtonpressed = 0;
        }
    }
    void includeFsharpButtonClicked()
    {
        if (includeFsharpButtonpressed == 0)
        {
            numbers[6] = 1;
            includeFsharpButton.setEnabled (false);
            includeFsharpButtonpressed = 1;
        }
        else
        {
            
            numbers[6] = 0;
            includeFsharpButton.setEnabled (true);
            includeFsharpButtonpressed = 0;
        }
    }
    void includeGButtonClicked()
    {
        if (includeGButtonpressed == 0)
        {
            numbers[7] = 1;
            includeGButton.setEnabled (false);
            includeGButtonpressed = 1;
        }
        else
        {
            
            numbers[7] = 0;
            includeGButton.setEnabled (true);
            includeGButtonpressed = 0;
        }
    }
    
    void includeGsharpButtonClicked()
    {
        if (includeDsharpButtonpressed == 0)
        {
            numbers[8] = 1;
            includeGsharpButton.setEnabled (false);
            includeGsharpButtonpressed = 1;
        }
        else
        {
            
            numbers[8] = 0;
            includeGsharpButton.setEnabled (true);
            includeGsharpButtonpressed = 0;
        }
    }
    void includeAButtonClicked()
    {
        if (includeAButtonpressed == 0)
        {
            numbers[9] = 1;
            includeAButton.setEnabled (false);
            includeAButtonpressed = 1;
        }
        else
        {
            
            numbers[9] = 0;
            includeGsharpButton.setEnabled (true);
            includeGsharpButtonpressed = 0;
        }
    }
    void includeAsharpButtonClicked()
    {
        if (includeAsharpButtonpressed == 0)
        {
            numbers[10] = 1;
            includeAsharpButton.setEnabled (false);
            includeAsharpButtonpressed = 1;
        }
        else
        {
            
            numbers[10] = 0;
            includeAsharpButton.setEnabled (true);
            includeAsharpButtonpressed = 0;
        }
    }
    void includeBButtonClicked()
    {
        if (includeBButtonpressed == 0)
        {
            numbers[11] = 1;
            includeBButton.setEnabled (false);
            includeBButtonpressed = 1;
        }
        else
        {
            
            numbers[11] = 0;
            includeBButton.setEnabled (true);
            includeBButtonpressed = 0;
        }
    }
    void resetButtonClicked()
    {
         filesPlayed = 0;
         choice =1;
         s=0;
        
         ss =0;
         i=0;
         ssa =0;
         sa =0;
         oct = 0;
         octaveRange = 2;

         numNotes = 2;
         notesButtonpressed = 0;
         eightNoteButtonpressed =0;
         oneOctaveButtonpressed = 0;
         includeCButtonpressed = 0;
         includeCsharpButtonpressed = 0;
         includeDButtonpressed = 0;
         includeDsharpButtonpressed = 0;
         includeEButtonpressed = 0;
         includeFButtonpressed = 0;
         includeFsharpButtonpressed = 0;
        
         includeGButtonpressed = 0;
         includeGsharpButtonpressed = 0;
         includeAButtonpressed = 0;
         includeAsharpButtonpressed = 0;
         includeBButtonpressed = 0;
         resetButtonpressed = 0;
         includeCButton.setEnabled (true);
         includeCsharpButton.setEnabled (true);
         includeDButton.setEnabled (true);
         includeDsharpButton.setEnabled (true);
         includeEButton.setEnabled (true);
         includeFButton.setEnabled (true);
         includeFsharpButton.setEnabled (true);
         includeGButton.setEnabled (true);
         includeGsharpButton.setEnabled (true);
         includeAButton.setEnabled (true);
         includeAsharpButton.setEnabled (true);
         includeBButton.setEnabled (true);
         resetButton.setEnabled (true);
         playButton.setEnabled (true);
         noteButton.setEnabled (true);
         eightNoteButton.setEnabled (true);
         oneOctaveButton.setEnabled (true);
        for (int j=0; i < 12; i++)
        {
            numbers[j] = 0;
        }
        transportSource.setPosition (0.0);
        myvector.clear();
        myvector.empty();
        
        changeState (Initial);

    }
    TextButton playButton;
    TextButton noteButton;
    TextButton eightNoteButton;
    TextButton oneOctaveButton;
    TextButton includeCButton;
    TextButton includeCsharpButton;
    TextButton includeDButton;
    TextButton includeDsharpButton;
    TextButton includeEButton;
    TextButton includeFButton;
    TextButton includeFsharpButton;
    TextButton includeGButton;
    TextButton includeGsharpButton;
    TextButton includeAButton;
    TextButton includeAsharpButton;
    TextButton includeBButton;
    TextButton resetButton;
    
    //Slider slider;
    //Slider slider;
    AudioFormatManager formatManager;
    ScopedPointer<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    TransportState state;
    char* note;
    char* newnote;
    unsigned long s = 0;
    int filesPlayed = 0;
    int choice =1;
    int f;
    int ss =0;
    unsigned long sa;
    int ssa;
    int i=0;
    int oct = 0;
    int octaveRange = 2;
    int noteToPlay;
    int numNotes = 2;
    int notesButtonpressed = 0;
    int eightNoteButtonpressed =0;
    int oneOctaveButtonpressed = 0;
    int includeCButtonpressed = 0;
    int includeCsharpButtonpressed = 0;
    int includeDButtonpressed = 0;
    int includeDsharpButtonpressed = 0;
    int includeEButtonpressed = 0;
    int includeFButtonpressed = 0;
    int includeFsharpButtonpressed = 0;

    int includeGButtonpressed = 0;
    int includeGsharpButtonpressed = 0;
    int includeAButtonpressed = 0;
    int includeAsharpButtonpressed = 0;
    int includeBButtonpressed = 0;
    int resetButtonpressed = 0;
    int found =0;

    
    // size of each binary file is the same
    int mp3Size = 21924;
    // boolean array of available notes from chrom scale
    int numbers[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    // vector to contain notes
    std::vector<int> myvector;
    
 

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
