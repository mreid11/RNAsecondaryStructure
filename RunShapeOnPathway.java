import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


public class RunShapeOnPathway {
	public static void main(String[] args) throws IOException{
		File file=new File("output.txt");
		File output=new File("out.txt");
		output.delete();
		Scanner in=new Scanner(file);
		String line=in.next();
		System.setOut(new PrintStream(new FileOutputStream(output, true)));
		String [] arguments={args[0],line};
		MakeShape.main(arguments);
		while(in.hasNext()){
			in.next();
			in.next();
			line=in.next();
			if(line.equals("O")) break;
			arguments[1]=line;
			MakeShape.main(arguments);
		}
		in.close();
	}
}
