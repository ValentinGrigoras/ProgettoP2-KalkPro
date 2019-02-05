public class Use {

    public static void main(String[] args) {
    	
    	//Punto
    	Punto a = new Punto(5,5);
    	Punto b = new Punto(5,7);
    	System.out.println("Distanza tra due punti: ");
    	System.out.println(Punto.distanzaDuePunti(a, b));
    	
    	
    	
    	//Triangolo
    	Forma p1 = new Triangolo(new Punto(3,3), new Punto(7,3), new Punto(5,7));
    	System.out.println("Perimetro Triangolo: ");
    	System.out.println(p1.getPerimetro());
    	System.out.println("Area Triangolo: ");
    	System.out.println(p1.getArea());
    	System.out.println("Baricentro Triangolo: ");
    	System.out.println("X: " + p1.getBaricentro().getX() + " Y: " + p1.getBaricentro().getY());
    	System.out.println("Altezza Triangolo: ");
    	Triangolo t = (Triangolo)p1;
    	System.out.println(t.getAltezza());
    	System.out.println("Numero Vertici Triangolo: ");
    	System.out.println(t.contaVertici());
    	System.out.println("Un Lato: ");
    	System.out.println(t.getLato(2));
    	System.out.println("Un Vertice: ");
    	System.out.println("X: " + t.getVertice(2).getX() + "Y: " + t.getVertice(2).getY());
    	
    	
    	//Quadrilatero
    	Forma p2 = new Quadrilatero(new Punto(3,3), new Punto(7,3), new Punto(7,6), new Punto(3,6));
    	System.out.println("Perimetro Quadrilatero: ");
    	System.out.println(p2.getPerimetro());
    	System.out.println("Area Quadrilatero: ");
    	System.out.println(p2.getArea());
    	System.out.println("Baricentro Quadrilatero: ");
    	System.out.println("X: " + p2.getBaricentro().getX() + " Y: " + p2.getBaricentro().getY());
    	
    	//Circonferenza
    	Forma p3 = new Circonferenza(new Punto(5,5), 3);
    	System.out.println("Perimetro Circonferenza: ");
    	System.out.println(p3.getPerimetro());
    	System.out.println("Area Circonferenza: ");
    	System.out.println(p3.getArea());
    	System.out.println("Baricentro Circonferenza: ");
    	System.out.println("X: " + p3.getBaricentro().getX() + " Y: " + p3.getBaricentro().getY());
    	System.out.println("Raggio Circonferenza: ");
    	Circonferenza c = (Circonferenza)p3;
    	System.out.println(c.getRaggio());
    	c.setRaggio(6);
    	System.out.println("Raggio Circonferenza dopo il set: ");
    	System.out.println(c.getRaggio());
    	
    	
    	
    	
    	
    }
}
