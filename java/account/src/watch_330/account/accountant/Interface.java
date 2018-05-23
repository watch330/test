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
			System.out.println("--------------��ͥ��֧�������------------");
			System.out.println("1 ��֧��ϸ");
			System.out.println("2 �Ǽ�����");
			System.out.println("3 �Ǽ�֧��");
			System.out.println("4 ��       ��");
			System.out.println("��ѡ��(1-4):");
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
				System.out.println("��û�м�¼!");
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
