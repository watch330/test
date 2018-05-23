package com.main;

import java.util.Scanner;

public class Triangle {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int number;
		while(in.hasNext()) {
			number = in.nextInt();
			int temp = number;
			for (int i = 0; i < number; i++) {
				for(int j=0;j<i;j++)
					System.out.print(" ");
				for (int k = 0; k <(temp+temp-1) ; k++) {
					System.out.print("*");
				}
				--temp;
				System.out.println();	
			}
		}
		in.close();
	}

}
