#!/bin/bash


printf "Starting the script ...\n\n"

# URL VARIABLE: THIS IS USED TO STORE THE URL (UNIFORM RESOURCE LOCATOR)
URL=https://stackoverflow.com/

# THIS LINE USES WGET SOFTWARE TO DOWNLOAD DOCUMENTS FROM THE INTERNET
wget $URL


printf "Ending the script..\n"

exit
