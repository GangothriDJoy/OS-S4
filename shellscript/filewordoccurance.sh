#!/bin/bash
set -u
search()
{
        filename=$1
        word=$2
        if [ -f "$filename" ]; then
                occurence=$(grep -o -i "$word" "$filename" | wc -l)
                if [ "$occurence" -gt 0 ]; then
                        echo "The word $word occures in the file $filename "
                        echo "Number of occurence = $occurence"
                else
                        echo "The word does not exists in the file"
                fi
        else
                echo "ERROR: file '$filename' not found"
        fi
        if [ ! -f "$filename" ]; then
                echo "file not found!"
        fi
}
echo -n "Enter the filename: "
read -r filename
echo -n "Enter the word to be searched for: "
read -r word
search "$filename" "$word"
words=$(wc -l < "$filename")



