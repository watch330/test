package watch_330.vehicleUser;

public class Car extends Vehicle {
	protected boolean manned = true;
	protected boolean goods = false;

	public void setCap() {
		System.out.println("�����ýγ���������:");
		manCap = Integer.parseInt(input.nextLine());
		
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
