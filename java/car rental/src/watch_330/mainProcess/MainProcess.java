package watch_330.mainProcess;

import java.util.Scanner;

import watch_330.vehicleUser.*;

public class MainProcess {

	public static void main(String[] args) {
		int choice;
		Manager manager = new Manager();
		User user = new User();
		Scanner input = new Scanner(System.in);

		System.out.println("�����Ա¼�복����Ϣ");
		manager.setInfo();
		System.out.println("����1����¼����Ϣ,����0�˳�");
		while ((choice = Integer.parseInt(input.nextLine())) == 1) {
			manager.setInfo();
			System.out.println("����1����¼����Ϣ,����0�˳�");
		}

		while (true) {
			showMainInterface();
			choice = Integer.parseInt(input.nextLine());
			switch (choice) {
			case 1:
				stop: {
					while (true) {
						showUserInterface();
						choice = Integer.parseInt(input.nextLine());
						switch (choice) {
						case 1:
							user.rendCar();
							break;
						case 2:
							user.showBill();
							break;
						case 3:
							break stop;
						}
					}
				}
				break;
			case 2:
				stop: {
					while (true) {
						showManagerInterface();
						choice = Integer.parseInt(input.nextLine());
						switch (choice) {
						case 1:
							manager.setInfo();
							break;
						case 2:
							manager.modifInfo();
							break;
						case 3:
							manager.deleteInfo();
							break;
						case 4:
							manager.showAllInfo();
							break;
						case 5:
							break stop;
						}
					}
				}
				break;
			case 3:
				input.close();
				System.exit(0);
			}
		}
	}

	private static void showManagerInterface() {
		System.out.println("-----------------------------------------");
		System.out.println("1.¼��    2.�޸�   3.ɾ��   4.�鿴������Ϣ    5.�˳�");
		System.out.println("��ѡ��:");
	}

	private static void showUserInterface() {
		System.out.println("-----------------------");
		System.out.println("1.�⳵    2.�鿴�˵�    3.�˳�");
		System.out.println("��ѡ��:");

	}

	private static void showMainInterface() {
		System.out.println("------------------------------");
		System.out.println("1.�û����       2.����Ա���   3.�˳�");
		System.out.println("��ѡ��:");
	}

}
