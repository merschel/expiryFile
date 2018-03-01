# Warning information

First! The programm works (at least for me) BUT since these project is in a early state I do NOT recommend to use this programm. I accept no liability for damages.

# Idea behind this project

Sometimes I create a file for a temporary purpose. A text file that include a link or a note, a picture or a audio record that I know that I want to save only for certain period of time. But its often happen that I forgot about the file. So this files unnecessarily occupy memory and polluting the hard disk.

Here I provide a programm with which one can flag a temporary file with a expiry date.

The workflow is as follow: 

1) The user create a File. For example 'note.txt'. Here he saves some information which are important for him for the next month.

2) after this he opens the console and type 

    expiryFile -p \[path to the temporary file\] -d \[expiry date\] -m \[modus\]

This register the file with the chosen expiry date. The expiry date have to be in the future and have to be in the format dd.mm.yyyy (this is the german format, more formats will follow). With the modus the user can define what will happend with the file when the expiry date is reach. Allowed are 0,1,2,3. With 0 the programm will delete the file without any information or ask for permission. With 1 the file will be deleted, but the user will get an information about it. With 2 the programm aks the user whether the file can be deletet or not. With 3 the user will get only a information that the file still exist. 

The commant 

    expiryFile -c

checks if some files are expired and treat it depending on the modus. This commant allows the user to check the files on a regulary. For exaple at the start of the system. 

With 

    expiryFile -l 

the programm will print the curred list. Here the user can also remove files from the list.

With 

    expiryFile -h

the programm will print some help informations. 

# Some remarks

In the currend state this programm work only with the console and as far I know only on windows.
