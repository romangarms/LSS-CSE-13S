if [ "$1" = "abc" ]
then
    echo dollar 1 is abc
    if [ "$2" = "def" ]
    then
        echo dollar 2 is def
    else
        echo dollar 2 is not def
    fi
else
    echo dollar 1 is not abc
fi
