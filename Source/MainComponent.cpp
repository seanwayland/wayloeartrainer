#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
//#include <random>
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
        // labels or all the various functions
        addAndMakeVisible (titleLabel);
        titleLabel.setFont (Font (6.0f));
        titleLabel.setText ("wayloeartrainer www.seanwayland.com", dontSendNotification);
        titleLabel.setColour (Label::textColourId, Colours::lightgreen);
        titleLabel.setJustificationType (Justification::left);
    
        addAndMakeVisible (instructionsLabel);
        instructionsLabel.setFont (Font (6.0f));
        instructionsLabel.setText ("select notes (left) then play  ", dontSendNotification);
        instructionsLabel.setColour (Label::textColourId, Colours::lightgreen);
        instructionsLabel.setJustificationType (Justification::left);
    
        addAndMakeVisible (instructions2Label);
        instructions2Label.setFont (Font (6.0f));
        instructions2Label.setText ("2,4 or 6 notes. 1 or 2 octaves.", dontSendNotification);
        instructions2Label.setColour (Label::textColourId, Colours::lightgreen);
        instructions2Label.setJustificationType (Justification::left);
    

    
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
        eightNoteButton.setButtonText ("play 6 notes");
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
        includeCButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        includeCButton.setEnabled (true);
    
        addAndMakeVisible (&playCButton);
        playCButton.setButtonText ("Play C");
        playCButton.addListener (this);
        playCButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        playCButton.setEnabled (true);
    
        addAndMakeVisible (&includeCsharpButton);
        includeCsharpButton.setButtonText ("Include C#");
        includeCsharpButton.addListener (this);
        includeCsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        includeCsharpButton.setEnabled (true);
    
        addAndMakeVisible (&playCsharpButton);
        playCsharpButton.setButtonText ("Play C#");
        playCsharpButton.addListener (this);
        playCsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        playCsharpButton.setEnabled (true);
    
    

    

    
        addAndMakeVisible (&includeDButton);
        includeDButton.setButtonText ("Include D");
        includeDButton.addListener (this);
        includeDButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        includeDButton.setEnabled (true);
    
        addAndMakeVisible (&playDButton);
        playDButton.setButtonText ("Play D");
        playDButton.addListener (this);
        playDButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        playDButton.setEnabled (true);
    
    
    
        addAndMakeVisible (&includeDsharpButton);
        includeDsharpButton.setButtonText ("Include D#");
        includeDsharpButton.addListener (this);
        includeDsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        includeDsharpButton.setEnabled (true);
    
        addAndMakeVisible (&playDsharpButton);
        playDsharpButton.setButtonText ("Play D#");
        playDsharpButton.addListener (this);
        playDsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        playDButton.setEnabled (true);

    
        addAndMakeVisible (&includeEButton);
        includeEButton.setButtonText ("Include E");
        includeEButton.addListener (this);
        includeEButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        includeEButton.setEnabled (true);
    
        addAndMakeVisible (&playEButton);
        playEButton.setButtonText ("Play E");
        playEButton.addListener (this);
        playEButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        playEButton.setEnabled (true);
    
        addAndMakeVisible (&includeFButton);
        includeFButton.setButtonText ("Include F");
        includeFButton.addListener (this);
        includeFButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        includeFButton.setEnabled (true);
    

    
        addAndMakeVisible (&playFButton);
        playFButton.setButtonText ("Play F");
        playFButton.addListener (this);
        playFButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        playFButton.setEnabled (true);
    
        addAndMakeVisible (&includeFsharpButton);
        includeFsharpButton.setButtonText ("Include F#");
        includeFsharpButton.addListener (this);
        includeFsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        includeFsharpButton.setEnabled (true);
    
        addAndMakeVisible (&playFsharpButton);
        playFsharpButton.setButtonText ("Play F#");
        playFsharpButton.addListener (this);
        playFsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        playFButton.setEnabled (true);
    
        addAndMakeVisible (&includeGButton);
        includeGButton.setButtonText ("Include G");
        includeGButton.addListener (this);
        includeGButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        includeGButton.setEnabled (true);
    
        addAndMakeVisible (&playGButton);
        playGButton.setButtonText ("Play G");
        playGButton.addListener (this);
        playGButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        playGButton.setEnabled (true);
    
        addAndMakeVisible (&includeGsharpButton);
        includeGsharpButton.setButtonText ("Include G#");
        includeGsharpButton.addListener (this);
        includeGsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        includeGsharpButton.setEnabled (true);
    
        addAndMakeVisible (&playGsharpButton);
        playGsharpButton.setButtonText ("Play G#");
        playGsharpButton.addListener (this);
        playGsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        playGButton.setEnabled (true);
    
        addAndMakeVisible (&includeAButton);
        includeAButton.setButtonText ("Include A");
        includeAButton.addListener (this);
        includeAButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        includeAButton.setEnabled (true);
    
        addAndMakeVisible (&playAButton);
        playAButton.setButtonText ("Play A");
        playAButton.addListener (this);
        playAButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        playAButton.setEnabled (true);
    
        addAndMakeVisible (&includeAsharpButton);
        includeAsharpButton.setButtonText ("Include A#");
        includeAsharpButton.addListener (this);
        includeAsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        includeAsharpButton.setEnabled (true);
    
        addAndMakeVisible (&playAsharpButton);
        playAsharpButton.setButtonText ("Play A#");
        playAsharpButton.addListener (this);
        playAsharpButton.setColour (TextButton::buttonColourId, Colours::blue);
        playAButton.setEnabled (true);
    
        addAndMakeVisible (&includeBButton);
        includeBButton.setButtonText ("Include B");
        includeBButton.addListener (this);
        includeBButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        includeBButton.setEnabled (true);
    
        addAndMakeVisible (&playBButton);
        playBButton.setButtonText ("Play B");
        playBButton.addListener (this);
        playBButton.setColour (TextButton::buttonColourId, Colours::lightsalmon);
        playBButton.setEnabled (true);
    
        addAndMakeVisible (&resetButton);
        resetButton.setButtonText ("reset");
        resetButton.addListener (this);
        resetButton.setColour (TextButton::buttonColourId, Colours::orange);
        resetButton.setEnabled (true);
    
        addAndMakeVisible (&repeatButton);
        repeatButton.setButtonText ("repeat");
        repeatButton.addListener (this);
        repeatButton.setColour (TextButton::buttonColourId, Colours::orange);
        repeatButton.setEnabled (true);
        //Desktop::getInstance().getDisplays().getMainDisplay().totalArea;
        //setSize(getWidth(), getHeight());
        setSize(600,600);
        

    
        formatManager.registerBasicFormats();       // [1]
        transportSource.addChangeListener (this);   

        setAudioChannels (0, 2);
    }
    
    // destructor
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
        //setSize(600,600);
        // sizing of all buttons in application

        playButton.setBounds (10, 10, getWidth()/2-10, getHeight()/10);
        repeatButton.setBounds (getWidth()/2, 10, getWidth()/2-10, getHeight()/10);
        noteButton.setBounds (10, getHeight()/10+10,  getWidth()/2-10, getHeight()/10);
        eightNoteButton.setBounds (getWidth()/2, getHeight()/10+10,  getWidth()/2-10, getHeight()/10);
        oneOctaveButton.setBounds (10, 2*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/10);
        resetButton.setBounds (getWidth()/2, 2*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/10);
        includeCButton.setBounds (10, 3*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        includeCsharpButton.setBounds (10, 3.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        includeDButton.setBounds (10, 4*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        includeDsharpButton.setBounds (10,4.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        includeEButton.setBounds (10, 5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        includeFButton.setBounds (10, 5.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        includeFsharpButton.setBounds (10, 6*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        includeGButton.setBounds (10, 6.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        includeGsharpButton.setBounds (10,7*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        includeAButton.setBounds (10, 7.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        includeAsharpButton.setBounds (10, 8*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        includeBButton.setBounds (10, 8.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playCButton.setBounds (getWidth()/2,3*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playCsharpButton.setBounds (getWidth()/2,3.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playDButton.setBounds (getWidth()/2, 4*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playDsharpButton.setBounds (getWidth()/2, 4.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playEButton.setBounds (getWidth()/2, 5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playFButton.setBounds (getWidth()/2, 5.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playFsharpButton.setBounds (getWidth()/2,  6*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playGButton.setBounds (getWidth()/2, 6.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playGsharpButton.setBounds (getWidth()/2,7*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playAButton.setBounds (getWidth()/2,7.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playAsharpButton.setBounds (getWidth()/2,8*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        playBButton.setBounds (getWidth()/2, 8.5*(getHeight()/10)+10,  getWidth()/2-10, getHeight()/20);
        titleLabel.setBounds (10, getHeight()-22,  getWidth()-20, 6);
        instructionsLabel.setBounds (10, getHeight()-16 ,getWidth()-20 , 6);
        instructions2Label.setBounds (10, getHeight()-10, getWidth()-20, 6);
        
        

    }
    

    // when a file stops playing the state is changed
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
      // methods for pressing of each button
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
        if (button == &repeatButton)  repeatButtonClicked();
        
        if (button == &playCButton)  playCButtonClicked();
        if (button == &playCsharpButton)  playCsharpButtonClicked();
        if (button == &playDButton)  playDButtonClicked();
        if (button == &playDsharpButton)  playDsharpButtonClicked();
        if (button == &playEButton)  playEButtonClicked();
        if (button == &playFButton)  playFButtonClicked();
        if (button == &playFsharpButton)  playFsharpButtonClicked();
        if (button == &playGButton)  playGButtonClicked();
        if (button == &playGsharpButton)  playGsharpButtonClicked();
        if (button == &playAButton)  playAButtonClicked();
        if (button == &playAsharpButton)  playAsharpButtonClicked();
        if (button == &playBButton)  playBButtonClicked();

        
        
    

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
                    // reset all variables and arrays to zero
                case Initial:
                    transportSource.setPosition (0.0);
                    filesPlayed = 0;
                    for (int h=0; h < 12; h++)
                    {
                        numbers[h] = 0;
                    }
                    for (int hh=0; hh<6; hh++)
                    {
                        notesPlayed[hh]=0;
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
                    // oneshot is a boolean which is set if a note is played once
                    if (oneShot==1)
                    {
                        oneShot =0;
                        changeState(Finished);
                        
                        
                    }
                    if (playClicked == 1)
                { // if play button is clicked and a file stops then keep choosing new notes and playing
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
                        // store notes played in notesPlayed array if needed to be repeated
                        notesPlayed[filesPlayed]=noteToPlay;
                        playfile(noteToPlay);
                        
                    }
                } // if repeat buttons is clicked and file stopped keep playing through rest of files
                    if (repeatClicked == 1)
                    {
                        
                        
                        if (repeatsPlayed <numNotes)
                        {
                            
                            noteToPlay = notesPlayed[repeatsPlayed];
                            playfile(noteToPlay);
                            repeatsPlayed ++ ;
                        }
                        else
                        {
                            changeState(Finished);
                            
                        }
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
                    filesPlayed=0;
                    repeatClicked =0;
                    playClicked=0;
                    
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
    

    void repeatButtonClicked()
    {

        repeatClicked =1;
        repeatsPlayed = 1;
        playfile(notesPlayed[0]);
        
    }
    
    void playButtonClicked()
    {
        
        if (filesPlayed == numNotes)
        {
            filesPlayed = 0;
        }
        myvector.clear();
        myvector.empty();

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
            notesPlayed[0]=noteToPlay;
            playfile(noteToPlay);
            playFilesToPlay = numNotes -1;
            playClicked = 1;
            
        }
    }
    // this button chooses that 4 notes will be played randomly
    void noteButtonClicked()
    {
        eightNoteButton.setEnabled (true);
        eightNoteButtonpressed=0;
        if (notesButtonpressed == 0)
        {
            filesPlayed=0;
            numNotes = 4;
            noteButton.setEnabled (false);
            notesButtonpressed = 1;
        }
        else
        {
            filesPlayed=0;
            numNotes = 2;
            noteButton.setEnabled (true);
            notesButtonpressed = 1;
        }
    }
    // this button chooses that 6 notes will be chosen randomly
    void eightnoteButtonClicked()
    {
        noteButton.setEnabled (true);
        notesButtonpressed =0;
        if (eightNoteButtonpressed == 0)
        {
            filesPlayed=0;
            numNotes = 6;
            eightNoteButton.setEnabled (false);
            eightNoteButtonpressed = 1;
        }
        else
        {
            filesPlayed=0;
            numNotes = 2;
            eightNoteButton.setEnabled (true);
            eightNoteButtonpressed = 1;
        }
    }
    // this button makes the range one octave instead of 2
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
    // methods that play all the notes 
    void playCButtonClicked()
    {
        oneShot=1;
        playfile(0);
        
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
    void playCsharpButtonClicked()
    {
        oneShot=1;
        playfile(1);
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
    void playDButtonClicked()
    {
        oneShot=1;
        playfile(2);
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
    void playDsharpButtonClicked()
    {
        oneShot=1;
        playfile(3);
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
    void playEButtonClicked()
    {
        oneShot=1;
        playfile(4);
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
    void playFButtonClicked()
    {
        oneShot=1;
        playfile(5);
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
    void playFsharpButtonClicked()
    {
        oneShot=1;
        playfile(6);
        
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
    void playGButtonClicked()
    {
        oneShot=1;
        playfile(7);
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
    void playGsharpButtonClicked()
    {
        oneShot=1;
        playfile(8);
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
    void playAButtonClicked()
    {
        oneShot=1;
        playfile(9);
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
    void playAsharpButtonClicked()
    {
        oneShot=1;
        playfile(10);
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
    void playBButtonClicked()
    {
        oneShot=1;
        playfile(11);
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
    Label titleLabel;
    Label instructionsLabel;
    Label instructions2Label;
    TextButton playButton;
    TextButton noteButton;
    TextButton eightNoteButton;
    TextButton oneOctaveButton;
    TextButton includeCButton;
    TextButton playCButton;
    TextButton includeCsharpButton;
    TextButton playCsharpButton;
    TextButton includeDButton;
    TextButton playDButton;
    TextButton includeDsharpButton;
    TextButton playDsharpButton;
    TextButton includeEButton;
    TextButton playEButton;
    TextButton includeFButton;
    TextButton playFButton;
    TextButton includeFsharpButton;
    TextButton playFsharpButton;
    TextButton includeGButton;
    TextButton playGButton;
    TextButton includeGsharpButton;
    TextButton playGsharpButton;
    TextButton includeAButton;
    TextButton playAButton;
    TextButton includeAsharpButton;
    TextButton playAsharpButton;
    TextButton includeBButton;
    TextButton playBButton;
    TextButton resetButton;
    TextButton repeatButton;
    
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
    int repeatButtonpressed = 0;
    int found =0;
    int playFilesToPlay=0;
    int playClicked=0;
    int repeatClicked=0;
    int repeatsPlayed=0;
    int oneShot=0;

    
    // size of each binary file is the same
    int mp3Size = 22968;
    // boolean array of available notes from chrom scale
    int numbers[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int notesPlayed[6] ={0,0,0,0,0,0};
    // vector to contain notes
    std::vector<int> myvector;
    
 

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
