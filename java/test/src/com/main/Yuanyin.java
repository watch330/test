package com.main;

import java.util.Scanner;

public class Yuanyin {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			String st = in.nextLine();
			String[] arr;
			String newStr="";
			arr=st.split(" ");
			for (int i = arr.length-1; i >= 0; i--) {
				newStr +=arr[i]+" ";
			}
			newStr = newStr.trim();
			System.out.println(newStr);
		}
		in.close();
	}
}
