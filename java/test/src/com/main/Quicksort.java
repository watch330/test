package com.main;

import java.util.Scanner;

public class Quicksort {

	public static void main(String[] args) {
		int num = 0;
		int top = 0;
		int button = 0;
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			num = in.nextInt();
			int[] arr = new int[num];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = in.nextInt();
			}
			button = 0;
			top = num - 1;
			quickSortMethod(arr, button, top);
			for (int i = 0; i < arr.length; i++)
				System.out.print(arr[i] + " ");
		}
		in.close();
	}

	public static void quickSortMethod(int[] a, int left, int right) {
		if (left < right) {
			int button = left;
			int top = right;
			int base = a[left];
			int divide = 0;
			while (button < top) {
				while (button < top && a[top] >= base) {
					top--;
				}
				if (button < top) {
					a[button] = a[top];
					button++;
				}
				while (button < top && a[button] <= base) {
					button++;
				}
				if (button < top) {
					a[top] = a[button];
					top--;
				}
			}
			divide = button;
			a[divide] = base;
			quickSortMethod(a, left, divide - 1);
			quickSortMethod(a, divide + 1, right);
		}
	}
}