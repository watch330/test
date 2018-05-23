package com.main;

import java.util.Scanner;

public class FactorizationDemo {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numbers = 0,temp;
		while (in.hasNext()) {
			numbers = in.nextInt();
			temp = numbers;
			int j = 2;
			while(temp!=1) {
				if(temp%j==0) {
					System.out.print(j+" ");
					temp /= j;
					j=2;
					continue;
				}else j++;
			}
			System.out.println();
		}
		in.close();
	}

}
//			for(int j =2;j<(int) Math.sqrt(numbers);j++) {
//				if(temp%j==0) {
//					System.out.print(j+" ");
//					temp /= j;
//					j=1;
//					continue;
//					}
//				if(temp==1)
//					System.out.println();
//					break;
//				}
