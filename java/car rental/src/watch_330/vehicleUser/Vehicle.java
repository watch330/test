package watch_330.vehicleUser;

import java.util.Scanner;

import watch_330.uility.Manager;

public class Vehicle implements Manager {
	protected String id;
	protected String brand;
	protected int rent;
	protected boolean manned;
	protected boolean goods;
	protected int manCap;
	protected int goodCap;
	protected Scanner input = new Scanner(System.in);

	public void setID() {
		System.out.println("������ID:");
		id = input.nextLine();
	}

	public void setBrand() {
		System.out.println("������Ʒ���ͺ�:");
		brand = input.nextLine();
	}

	public void setRent() {
		System.out.println("���������(Ԫ/��):");
		rent = Integer.parseInt(input.nextLine());
	}

	public void setCap() {
	}

	public void showInfo() {
	}

	public void modifyInfo() {
		setBrand();
		setRent();
		setCap();

	}

}
