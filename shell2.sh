#!/bin/bash
#!/bin/bash
X="-n"
Y="-n"
if [ $X = "$Y" ] ; then
        echo "X=Y"
fi
if [ -n "" ] ; then
        echo "X=Y   sdf"
fi
for X in red green blue
do
    echo $X
done
echo *
