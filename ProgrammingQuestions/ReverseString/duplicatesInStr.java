package com.main;

import java.util.HashSet;

public class PracticeMain {
    public static void main(String[] args) {
        String refStr = "dsfasd";
        HashSet<Character> duplChars = new HashSet<>();
        HashSet<Character> seenChars = new HashSet<>();

        // Efficiently track duplicate characters
        for (char c : refStr.toCharArray()) {
            if (!seenChars.add(c)) { // If already present in seenChars, it's a duplicate
                duplChars.add(c);
            }
        }

        // Print duplicate characters
        System.out.println("Duplicate characters: " + duplChars);
    }
}