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
		System.out.println("请输入您要租车的数量:");
		times = Integer.parseInt(input.nextLine());
		if (!isRendNumRight(times, Manager.carList.size())) {
			System.out.println("只有" + Manager.carList.size() + "辆车!");
			System.out.println("请重新输入要租车的数量:");
			times = Integer.parseInt(input.nextLine());
			while (!isRendNumRight(times, Manager.carList.size())) {
				System.out.println("只有" + Manager.carList.size() + "辆车!");
				System.out.println("请重新输入要租车的数量:");
				times = Integer.parseInt(input.nextLine());
			}
		}
		for (int i = 0; i < times; i++) {
			int tempInputId;
			System.out.println("请输入第" + (i + 1) + "辆车的ID:");
			tempInputId = Integer.parseInt(input.nextLine());
			if (isRendIDright(tempInputId)) {
				rentCar.add(tempInputId);
			} else {
				System.out.println("Id不存在,请重新输入");
				tempInputId = Integer.parseInt(input.nextLine());
				while (!isRendIDright(tempInputId)) {
					System.out.println("Id不存在,请重新输入");
					tempInputId = Integer.parseInt(input.nextLine());
				}
				rentCar.add(tempInputId);
			}
		}
		System.out.println("请输入要租的天数");
		rendDays = Integer.parseInt(input.nextLine());
	}

	public void showBill() {
		int money=0;
		int people =0;
		int good =0;
		System.out.println("---------------------您的账单-----------------------");
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
		System.out.println("共计花费:"+money+"元   共计可载人:"+people+"人   共计可载货"+good+"吨");
		

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
