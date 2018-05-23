package watch_330.vehicleUser;

public class Car extends Vehicle {
	protected boolean manned = true;
	protected boolean goods = false;

	public void setCap() {
		System.out.println("请设置轿车的载人数:");
		manCap = Integer.parseInt(input.nextLine());
		
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
