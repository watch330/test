package watch_330.vehicleUser;

public class Truck extends Vehicle {
	protected boolean manned = false;
	protected boolean goods = true;
	public void setCap() {
		System.out.println("�����û������ػ�����:");
		goodCap = Integer.parseInt(input.nextLine());
	}
	public void showInfo() {
		System.out.print("ID:" + id + "\t" + "Ʒ���ͺ�: " + brand + "   ");
		if (manned) {
			System.out.print("�ؿ�:" + manCap + "��\t");
		}
		if (goods) {
			System.out.print("�˻�:" + goodCap + "��\t");
		}
		System.out.println("���:"+rent+"Ԫ");
		System.out.println("--------------------------------------------------------");
	}
}
