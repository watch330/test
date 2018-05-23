package watch_330.mainProcess;

import java.util.Scanner;

import watch_330.vehicleUser.*;

public class MainProcess {

	public static void main(String[] args) {
		int choice;
		Manager manager = new Manager();
		User user = new User();
		Scanner input = new Scanner(System.in);

		System.out.println("请管理员录入车辆信息");
		manager.setInfo();
		System.out.println("输入1继续录入信息,输入0退出");
		while ((choice = Integer.parseInt(input.nextLine())) == 1) {
			manager.setInfo();
			System.out.println("输入1继续录入信息,输入0退出");
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
		System.out.println("1.录入    2.修改   3.删除   4.查看所有信息    5.退出");
		System.out.println("请选择:");
	}

	private static void showUserInterface() {
		System.out.println("-----------------------");
		System.out.println("1.租车    2.查看账单    3.退出");
		System.out.println("请选择:");

	}

	private static void showMainInterface() {
		System.out.println("------------------------------");
		System.out.println("1.用户入口       2.管理员入口   3.退出");
		System.out.println("请选择:");
	}

}
