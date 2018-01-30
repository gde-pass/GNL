
if [ "$(cat Tocompare.txt)" == "$(cat get_next_line.h)" ] ;then
    :
else
    echo "There is a difference !"
fi
