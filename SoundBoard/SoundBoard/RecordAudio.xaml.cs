﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using SoundBoard.Resources;
using Coding4Fun.Toolkit.Audio;
using Coding4Fun.Toolkit.Audio.Helpers;
using System.IO;
using System.IO.IsolatedStorage;
using Coding4Fun.Toolkit.Controls;
using SoundBoard.ViewModels;
using Newtonsoft.Json;

namespace SoundBoard
{
    public partial class RecordAudio : PhoneApplicationPage
    {
    
        private MicrophoneRecorder _recorder = new MicrophoneRecorder();
        private IsolatedStorageFileStream _audioStream;
        private string _tempFileName = "tempWav.wav";
        public RecordAudio()
        {
            InitializeComponent();

            BuildLocalizedApplicationBar();

        }
        private void BuildLocalizedApplicationBar()
        {
            ApplicationBar = new ApplicationBar();

            ApplicationBarIconButton recordAudioAppBar =
                new ApplicationBarIconButton();

            recordAudioAppBar.IconUri = new Uri("/Assets/AppBar/save.png", UriKind.Relative);
            recordAudioAppBar.Text = AppResources.AppBarSave;

            recordAudioAppBar.Click += recordAudioAppBar_Click;

            ApplicationBar.Buttons.Add(recordAudioAppBar);
            ApplicationBar.IsVisible = false;
        }

        void recordAudioAppBar_Click(object sender, EventArgs e)
        {
            InputPrompt fileName = new InputPrompt();

            fileName.Title = "Sound Name";
            fileName.Message = "What Should we call the sound?";

            fileName.Completed += FileNameCompleted;

            fileName.Show();
        }

        private void FileNameCompleted(object sender, PopUpEventArgs<string, PopUpResult> e)
        {
            if (e.PopUpResult == PopUpResult.Ok)
            {
                // Create a Sound object
                SoundData soundData = new SoundData();
                soundData.FilePath = string.Format("/customAudio/{0}.wav", DateTime.Now.ToFileTime());
                soundData.Title = e.Result;


                // Save wav file into director /customAudio/
                using (IsolatedStorageFile isoStore = IsolatedStorageFile.GetUserStoreForApplication()) {
                    if (!isoStore.DirectoryExists("/customAudio/"))
                        isoStore.CreateDirectory("/customAudio/");

                    isoStore.MoveFile(_tempFileName, soundData.FilePath);
                }



                // Add the SoundData to App.ViewModel.CustomSounds
                App.ViewModel.CustomSounds.Items.Add(soundData);



                // Save the list of CustomeSounds to Isolated Storage.ApplicationSettings
                var data = JsonConvert.SerializeObject(App.ViewModel.CustomSounds);

                IsolatedStorageSettings.ApplicationSettings[SoundModel.CustomSoundKey] = data;
                IsolatedStorageSettings.ApplicationSettings.Save();


                // We'll need to modify our Soundmodel to retreive CustomSounds
                //  from IsolatedStorage.ApplicationSettings

                NavigationService.Navigate(new Uri("/MainPage.xaml", UriKind.RelativeOrAbsolute));
            }
        }

        private void RecordAudioChecked(object sender, RoutedEventArgs e)
        {
            PlayAudio.IsEnabled = false;
            ApplicationBar.IsVisible = false;
            RotateCircle.Begin();
            _recorder.Start();

        }


        private void RecordAudioUnchecked(object sender, RoutedEventArgs e)
        {
            _recorder.Stop();

            SaveTempAudio(_recorder.Buffer);

            PlayAudio.IsEnabled = true;
            ApplicationBar.IsVisible = true;
            RotateCircle.Stop();
        }

       
        private void SaveTempAudio(MemoryStream buffer)
        {
            // Be defensive.... trust nobody
            if (buffer == null)
                throw new ArgumentNullException("Attempting a save an empty sound buffer.");

            // Clean out the AudioPlayer's hold on our audioStream
            if(_audioStream != null)
            {
                AudioPlayer.Stop();
                AudioPlayer.Source = null;

                _audioStream.Dispose();
            }

            var bytes = buffer.GetWavAsByteArray(_recorder.SampleRate);

            using (IsolatedStorageFile isoStore = IsolatedStorageFile.GetUserStoreForApplication()) {
                if (isoStore.FileExists(_tempFileName))
                    isoStore.DeleteFile(_tempFileName);

                _tempFileName = string.Format("{0}.wav", DateTime.Now.ToFileTime());
                _audioStream = isoStore.CreateFile(_tempFileName);
                _audioStream.Write(bytes, 0, bytes.Length);
                // Play ... SetSource of a MediaElement
                AudioPlayer.SetSource(_audioStream);
            }


        }

        private void PlayAudioClick(object sender, RoutedEventArgs e)
        {
            AudioPlayer.Play();
        }
    }
}