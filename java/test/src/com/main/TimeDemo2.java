package com.main;

import java.util.Calendar;
import java.util.Scanner;

public class TimeDemo2 {

	public static void main(String[] args) {
		Calendar time = Calendar.getInstance();
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			time.set(in.nextInt(), (in.nextInt()-1),in.nextInt());
			System.out.println(time.get(Calendar.DAY_OF_YEAR));
		}
		in.close();
	}

}
