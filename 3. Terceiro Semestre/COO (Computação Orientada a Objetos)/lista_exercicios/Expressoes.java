class Valor {

	private int v;

	public Valor(int v){

		this.v = v;
	}

	public int calculaValor(){

		return v;
	}
}

class OperadorSoma {

	private Object op1, op2;

	public OperadorSoma(Object op1, Object op2){
	
		this.op1 = op1;
		this.op2 = op2;
	}

	public int calculaSoma(){

		int v1 = 0;
		int v2 = 0;

		if(op1 instanceof Valor) v1 = ((Valor)op1).calculaValor();
		else if(op1 instanceof OperadorSoma) v1 = ((OperadorSoma)op1).calculaSoma();
		else if(op1 instanceof OperadorSubtracao) v1 = ((OperadorSubtracao)op1).calculaSubtracao();
		else System.out.println("Operando 1 desconhecido! Desconsidere o resultado da expressão!");
		// throw new Exception(""); //

		if(op2 instanceof Valor) v2 = ((Valor)op2).calculaValor();
		else if(op2 instanceof OperadorSoma) v2 = ((OperadorSoma)op2).calculaSoma();
		else if(op2 instanceof OperadorSubtracao) v2 = ((OperadorSubtracao)op2).calculaSubtracao();
		else System.out.println("Operando 2 desconhecido! Desconsidere o resultado da expressão!");

		return v1 + v2;
	}
}

class OperadorSubtracao {

	private Object op1, op2;

	public OperadorSubtracao(Object op1, Object op2){
	
		this.op1 = op1;
		this.op2 = op2;
	}

	public int calculaSubtracao(){

		int v1 = 0;
		int v2 = 0;

		if(op1 instanceof Valor) v1 = ((Valor)op1).calculaValor();
		else if(op1 instanceof OperadorSoma) v1 = ((OperadorSoma)op1).calculaSoma();
		else if(op1 instanceof OperadorSubtracao) v1 = ((OperadorSubtracao)op1).calculaSubtracao();
		else System.out.println("Operando 1 desconhecido! Desconsidere o resultado da expressão!");

		if(op2 instanceof Valor) v2 = ((Valor)op2).calculaValor();
		else if(op2 instanceof OperadorSoma) v2 = ((OperadorSoma)op2).calculaSoma();
		else if(op2 instanceof OperadorSubtracao) v2 = ((OperadorSubtracao)op2).calculaSubtracao();
		else System.out.println("Operando 2 desconhecido! Desconsidere o resultado da expressão!");

		return v1 - v2;
	}
}

public class Expressoes {

	public static void calculaExpressoes(Object [] expressoes){

		for(Object exp : expressoes){

			int resultado = 0;

			if(exp instanceof Valor) 
				resultado = ((Valor)exp).calculaValor();
			
			else if(exp instanceof OperadorSoma) 
				resultado = ((OperadorSoma)exp).calculaSoma();
			
			else if(exp instanceof OperadorSubtracao) 
				resultado = ((OperadorSubtracao)exp).calculaSubtracao();
			
			else System.out.println("O tipo da expressao é desconhecido! Desconsidere o resultado da mesma!");

			System.out.println("Resultado da expressão: " + resultado);
		}
	}

	public static void main(String [] args){

		Object [] expressoes = new Object[4];

		expressoes[0] = new Valor(10);
		expressoes[1] = new OperadorSoma(new Valor(11), new Valor(12));
		expressoes[2] = new OperadorSubtracao(new OperadorSoma(new Valor(13), new Valor(14)), new Valor(15));
		expressoes[3] = new OperadorSubtracao(new Valor(13), new OperadorSoma(new Valor(14), new Valor(15)));
	
		calculaExpressoes(expressoes);
	}
}
