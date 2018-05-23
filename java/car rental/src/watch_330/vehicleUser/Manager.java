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
		System.out.println("����Ҫɾ����Ϣ������ID:");
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
		System.out.println("����Ҫ�޸���Ϣ������ID:");
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
			System.out.println("����Ա��û��¼�복����Ϣ!");
		}
	}

	private void newVehicle() {
		System.out.println("������Ҫ¼�복��������(1 2 3�ֱ����γ� Ƥ�� ����):");
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
