package com.main;

import java.util.Scanner;

public class Method {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("������x,-1�˳�");
		int x = sc.nextInt();
		while(x!=-1) {
			System.out.println(sum(x));
			x = sc.nextInt();
		}
		System.out.println("�˳�");
		sc.close();
	}

	public static long sum(int num) {
		long sum = 0;
		for (int i = 1; i <= 10; i++) {
			sum += Math.pow(num, i);
		}
		return sum;
	}

}
