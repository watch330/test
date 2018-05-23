package watch_330.account.accountant;

import java.util.Scanner;

public class Interface {
	int choice;
	boolean isFirst = true;
	Scanner tempInput = new Scanner(System.in);

	Account acc = new Account();

	public void showInterface() {
		while (true) {
			if (isFirst) {
				isFirst = false;
			} else {
				for (int i = 0; i < 30; i++) {
					System.out.println();
				}
			}
			System.out.println("--------------家庭收支记账软件------------");
			System.out.println("1 收支明细");
			System.out.println("2 登记收入");
			System.out.println("3 登记支出");
			System.out.println("4 退       出");
			System.out.println("请选择(1-4):");
			getChoice();
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
		}
	}

	private void getChoice() {
		choice = tempInput.nextInt();
		if (choice == 1) {
			if (acc.isListEmpty())
				System.out.println("还没有记录!");
			else
				acc.showDetails();
		} else if (choice == 2) {
			acc.setIn();
		} else if (choice == 3) {
			acc.setOut();
		} else if (choice == 4) {
			acc.quit();
		}
	}

}
