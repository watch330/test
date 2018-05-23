package watch_330.vehicleUser;

import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class User {
	Scanner input = new Scanner(System.in);
	Manager tempMana = new Manager();
	List<Integer> rentCar = new ArrayList<Integer>();
	int times;

	int rendDays;

	public void rendCar() {
		
		tempMana.showAllInfo();
		System.out.println("��������Ҫ�⳵������:");
		times = Integer.parseInt(input.nextLine());
		if (!isRendNumRight(times, Manager.carList.size())) {
			System.out.println("ֻ��" + Manager.carList.size() + "����!");
			System.out.println("����������Ҫ�⳵������:");
			times = Integer.parseInt(input.nextLine());
			while (!isRendNumRight(times, Manager.carList.size())) {
				System.out.println("ֻ��" + Manager.carList.size() + "����!");
				System.out.println("����������Ҫ�⳵������:");
				times = Integer.parseInt(input.nextLine());
			}
		}
		for (int i = 0; i < times; i++) {
			int tempInputId;
			System.out.println("�������" + (i + 1) + "������ID:");
			tempInputId = Integer.parseInt(input.nextLine());
			if (isRendIDright(tempInputId)) {
				rentCar.add(tempInputId);
			} else {
				System.out.println("Id������,����������");
				tempInputId = Integer.parseInt(input.nextLine());
				while (!isRendIDright(tempInputId)) {
					System.out.println("Id������,����������");
					tempInputId = Integer.parseInt(input.nextLine());
				}
				rentCar.add(tempInputId);
			}
		}
		System.out.println("������Ҫ�������");
		rendDays = Integer.parseInt(input.nextLine());
	}

	public void showBill() {
		int money=0;
		int people =0;
		int good =0;
		System.out.println("---------------------�����˵�-----------------------");
		for (int i = 0; i < rentCar.size(); i++) {
			for (int j = 0; j < Manager.carList.size(); j++) {
				if (rentCar.get(i) == Integer.parseInt(Manager.carList.get(j).id)) {
					Manager.carList.get(j).showInfo();
					money+=Manager.carList.get(j).rent*rendDays;
					people+=Manager.carList.get(j).manCap*times;;
					good+=Manager.carList.get(j).goodCap*times;;
				}
			}
		}
		System.out.println("���ƻ���:"+money+"Ԫ   ���ƿ�����:"+people+"��   ���ƿ��ػ�"+good+"��");
		

	}

	private boolean isRendNumRight(int numbers, int target) {
		if (numbers > target) {
			return false;
		} else {
			return true;
		}
	}

	private boolean isRendIDright(int numbers) {
		for (Vehicle vehicle : Manager.carList) {
			if (numbers == Integer.parseInt(vehicle.id))
				return true;
		}
		return false;
	}
}
