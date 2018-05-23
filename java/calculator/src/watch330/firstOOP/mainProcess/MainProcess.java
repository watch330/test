package watch330.firstOOP.mainProcess;

import watch330.firstOOP.calculator.CircleCalculator;
import watch330.firstOOP.calculator.TriangleCalculator;

public class MainProcess {

	public static void main(String[] args) {
		CircleCalculator circle = new CircleCalculator();
		TriangleCalculator triangle = new TriangleCalculator();
		
		triangle.setParameter();
		triangle.showInfo();
		triangle.getArea();
		
		System.out.println();
		
		circle.setParameter();
		circle.showInfo();
		circle.getArea();
		
		
	}

}
