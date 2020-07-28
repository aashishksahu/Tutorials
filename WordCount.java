/*
* program to display the words and the number of times
* it has been used in the article and to display the
* words using lower case and in alphabetical order
*
* Basic use of Java Collections
*
* */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.Scanner;

public class WordCount {
    public static void main(String[] args) {

        // User input in String
        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();

        // split the string store it as a list in ArrayList
        ArrayList<String> words = new ArrayList<String>(Arrays.asList(text.toLowerCase().split("[,;:.?! ]")));

        // remove empty strings (spaces)
        for (int i = 0; i < words.size(); i++) {
            if (words.get(i).isEmpty()) {
                words.remove(i);
                i--;
            }
        }

        // HashMap is a Java collection class to store data in key value pairs
        // just like python dictionary or JSON
        // TreeMap is similar to HashMap except it stores data in sorted form
        TreeMap<String, Integer> count = new TreeMap<String, Integer>();

        // Java 8 foreach to iterate over an ArrayList
        words.forEach((item) -> {
            // count the occurence of each word
            int counter = 0;
            for (int i = 0; i < words.size(); i++) {
                if (words.get(i).equals(item)) {
                    counter++;
                }
            }

            // store it as key: word and value: word count
            count.put(item, counter);
            //reset counter
            counter = 0;
        });

        System.out.println(count);

    }
}