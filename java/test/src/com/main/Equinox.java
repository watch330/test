package com.main;

import java.util.Scanner;

public class Equinox {

	public static void main(String[] args) {
		int flag = 0;
		Scanner in = new Scanner(System.in);
		int lenth = 0, searchNum = 0;
		while (in.hasNext()) {
			int button = 0, top = 0, mid = 0;
			flag = 0;
			lenth = in.nextInt();
			int[] arr = new int[lenth];

			for (int i = 0; i < arr.length; i++) {
				arr[i] = in.nextInt();
			}
			searchNum = in.nextInt();
			top = lenth - 1;
			while (button <= top) {
				mid = (int) (top + button) / 2;
				if (searchNum > arr[mid])
					button = mid + 1;
				else if (searchNum < arr[mid])
					top = mid - 1;
				else if (searchNum == arr[mid]) {
					System.out.println(mid);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				System.out.println("no");
		}
		in.close();

	}

}
