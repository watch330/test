package watch_330.vehicleUser;

public class Truck extends Vehicle {
	protected boolean manned = false;
	protected boolean goods = true;
	public void setCap() {
		System.out.println("请设置货车的载货吨数:");
		goodCap = Integer.parseInt(input.nextLine());
	}
	public void showInfo() {
		System.out.print("ID:" + id + "\t" + "品牌型号: " + brand + "   ");
		if (manned) {
			System.out.print("载客:" + manCap + "人\t");
		}
		if (goods) {
			System.out.print("运货:" + goodCap + "吨\t");
		}
		System.out.println("租金:"+rent+"元");
		System.out.println("--------------------------------------------------------");
	}
}
