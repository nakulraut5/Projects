package com.main;

import java.util.Arrays;

public class PracticeMain {
	public static void main(String[] args) {
		long startTime = System.nanoTime();
		//REVERSE CHAR ARRAY EXERCISE
		char mainArray[]= new char[5];
		for(int i=0;i<mainArray.length;i++) {
			mainArray[i]=(char)('A'+i);
		}
		System.out.println("Main array: "+Arrays.toString(mainArray));
		char revArray[]=new char[5];
		int j=0;
		for(int i=4;i>=0;i--) {
			revArray[j]=mainArray[i];
			j++;
		}
		System.out.println("Reverse array: "+Arrays.toString(revArray));
		long endTime = System.nanoTime();  // End time tracking
        System.out.println("Execution Time: " + (endTime - startTime) + " nanoseconds");
	}
}