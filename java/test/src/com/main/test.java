package com.main;

import java.util.Scanner;

public class test {
	public static void main(String[] args) {
		int a = 0, b = 0;
		Scanner in = new Scanner(System.in);
		while (true) {
			if (in.hasNextInt()) {
				a = in.nextInt();
				break;
			}
		}
		while (true) {
			if (in.hasNextInt()) {
				b = in.nextInt();
				break;
			}
		}
		System.out.println(Math.abs(a - b));
		in.close();
	}
}
