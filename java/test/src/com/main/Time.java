package com.main;

import java.util.Scanner;

public class Time {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("������Ҫת��������,-1�˳�");
		int second = sc.nextInt();
		int min = 0, hour = 0, day = 0;
		while (second != -1) {
			day = second / (3600 * 24);
			hour = (second % (3600 * 24)) / 3600;
			min = (second % 3600) / 60;
			second -= day * (3600 * 24) + hour * 3600 + min * 60;
			System.out.println(day + "d:" + hour + "h:" + min + "m:" + second + "s");
			second = sc.nextInt();
		}
		System.out.println("�������");
		sc.close();

	}

}
