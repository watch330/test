package com.main;

import java.util.Scanner;

public class Maopao {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int lenth = 0;
		while (in.hasNext()) {
			lenth = in.nextInt();
			int[] arr = new int[lenth];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = in.nextInt();
			}
			for (int j = 0; j < arr.length - 1; j++) {
				for (int i = 0; i < arr.length - 1; i++) {
					if (arr[i] > arr[i + 1]) {
						int temp = arr[i + 1];
						arr[i + 1] = arr[i];
						arr[i] = temp;
					}
				}

			}
			for (int i = 0; i < arr.length; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
		}
		in.close();
	}

}
