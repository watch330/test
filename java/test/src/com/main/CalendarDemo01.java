package com.main;

import java.util.Scanner;

public class CalendarDemo01 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int year, month, day,days=0;
		int[] notLeapDays = {31,28,31,30,31,30,31,31,30,31,30,31};
		int[] LeapDays = {31,29,31,30,31,30,31,31,30,31,30,31};
		while (in.hasNext()) {
			year = in.nextInt();
			month = in.nextInt();
			day = in.nextInt();
			if (isLeapYear(year)^isAfterFeb(month)) {
				for(int i=0;i<month-1;i++) {
					days+=notLeapDays[i];
				}
				days +=day;
			}else {
				for(int i=0;i<month-1;i++) {
					days+=LeapDays[i];
				}
				days +=day;
			}
			System.out.println(days);
			days = 0;
		}
		in.close();

	}

	public static boolean isLeapYear(int num) {
		if(num%4==0&&num%100!=0||num%400==0)
			return true;
		else
			return false;
	}
	public static boolean isAfterFeb(int num) {
		if(num>2)
			return true;
		else
			return false;
	}
	

}
