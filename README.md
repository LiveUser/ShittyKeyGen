# Shitty Key Generator

The key generator that only runs commands and doesn't actually generate the keys

Hecho en 🇵🇷 por Radamés J. Valentín Reyes

# Description

The commands that the code automatically runs are the ones listed in [this website](https://flutter.dev/docs/deployment/android#signing-the-app) as an attempt to simplify running the commands by prompting the user only for the non-static information and leaving everything else as it is. Automating the process is just meant to speed up the process and remove any error that you may do while rewriting and editing the super long, boring command for key generation.

# Note

Your computer must already have the software required to run the "keytool" command

 # How to use

Just run the shittyKeyGen.exe from this repo if you are on windows or compile the shittyKeyGen.cpp yourself because its open-source

# Contributors

Special thanks to these people for their ideas and contributions

- Juan O. Lopez (Director of the department of computer science at the University of Puerto Rico at Arecibo)

  His suggestion was to use something like the sample code below to automatically detect the OS rather than prompting the user to manually input which OS they were using(like I did at first).

  ~~~c++
  isWindows = false;
  #if _WIN64
      isWindows =  true; // 64-bit Windows
  #elif _WIN32
      isWindows = true; // 32-bit Windows
  ~~~

# Important details

I found out that you cannot go over a 10k days limit when generating the key. If you do it sets itself to a very small number which makes it invalid to be used on the Google Play store, so I updated this app with the maximum 10k limit.

Specified at [authentication - OpenSSH : Key-based authorization, maximum key length - Server Fault](https://serverfault.com/questions/160268/openssh-key-based-authorization-maximum-key-length#:~:text=There is no maximum key,for a 17kbit RSA key.)