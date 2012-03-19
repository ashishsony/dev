#!/bin/sh
inc() {
       local value=4  
          echo "value is $value within the function\\n"
             echo "\\b\$1 is $1 within the function"
         }

         value=5
         echo value is $value before the function
         echo "\$1 is $1 before the function"
         echo
         echo -e $(inc $value) 
         echo
         echo value is $value after the function
         echo "\$1 is $1 after the function"
                   
