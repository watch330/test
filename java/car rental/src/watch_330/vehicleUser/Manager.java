package watch_330.vehicleUser;

import java.util.List;
import java.util.Scanner;

import java.util.ArrayList;

public class Manager {
	public static List<Vehicle> carList = new ArrayList<Vehicle>();
	Scanner input = new Scanner(System.in);
	Vehicle temp;

	public void setInfo() {
		newVehicle();
		temp.setID();
		temp.setBrand();
		temp.setRent();
		temp.setCap();
		carList.add(temp);
	}
	public void deleteInfo() {
		String target;
		showAllInfo();
		System.out.println("输入要删除信息车辆的ID:");
		target = input.nextLine();
		for (int i = carList.size()-1; i >= 0; i--) {
			String tempId = carList.get(i).id;
			if(tempId.equals(target)) {
				carList.remove(carList.get(i));
			}
		}
	}

	public void modifInfo() {
		String tempId;
		showAllInfo();
		System.out.println("输入要修改信息车辆的ID:");
		tempId = input.nextLine();
		for (Vehicle vehicle : carList) {
			if(vehicle.id.equals(tempId)) {
				vehicle.modifyInfo();
			}
		}
		
	}

	public void showAllInfo() {
		if (!carList.isEmpty()) {
			for (Vehicle vehicle : carList) {
				vehicle.showInfo();
			}
		} else {
			System.out.println("管理员还没有录入车辆信息!");
		}
	}

	private void newVehicle() {
		System.out.println("请输入要录入车辆的类型(1 2 3分别代表轿车 皮卡 货车):");
		switch (Integer.parseInt(input.nextLine())) {
		case 1:
			temp = new Car();
			break;
		case 2:
			temp = new Pickup();
			break;
		case 3:
			temp = new Truck();
			break;
		}
	}

}
