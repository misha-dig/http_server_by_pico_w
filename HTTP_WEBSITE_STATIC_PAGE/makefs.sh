#/bin/bash

ls -lh own_fsdata.c # Show file parameter of OLD filesystem data for lwIP

rm -rf own_fsdata.c # Remove OLD file system code 

./makefsdata # Make NEW fsdata.c with array and http server request 

mv fsdata.c own_fsdata.c # Rename into own_fsdata.c from orignal name of file fsdata.c, becuase we will confuse very easy and run a default website if we use fsdata.c code 

ls -lh own_fsdata.c # Show file parameter of NEW filesystem data for lwIP