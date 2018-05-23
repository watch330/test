package watch330.firstOOP.uility;

import java.util.Scanner;

public abstract class AreaCalculator {
	protected String type = "¶à±ßÐÎ";
	protected final static Scanner input = new Scanner(System.in);
	protected double area = 0.0D;

	protected void getType() {
		System.out.println(type);
	}

	protected abstract boolean checkInfo();

	protected abstract void calculateArea();

}
