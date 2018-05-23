package com.main;

public class Sum {
	public static void main(String[] args) {
		long totallSum = 0,sum = 1;
		for (int i = 1; i <= 10; i++) {
			sum*=i;
			totallSum+=sum;
		}
		System.out.println(totallSum);
	}

}
