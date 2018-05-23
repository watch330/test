package com.main;

import java.util.Scanner;

public class Add {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int quanlity = 0;
		while (in.hasNext()) {
			quanlity = in.nextInt();
			for (int i = 13; i <= quanlity; i += 2) {
				for (int j = 1,temp=0; j < (int) Math.sqrt(i); j++) {
					int t = i - j * j;
					int tt = (int) Math.sqrt(t);
					if(temp==t)
						break;
					if (tt * tt + j * j == i) {
						System.out.println(i + "=" + j * j + "+" + t);
						temp = j*j;
					}
				}
			}
		}
		in.close();
	}
}
