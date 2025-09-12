public class Simulacao {
    public void simularEscalonador(){
        // apagar o que ja tinha sido feito anteriormente
        LeituraPrograma.apagarLogs();

        //teste com quantums de 1 a 21
        for(int i = 1; i <= 21; i++){
            System.out.println("\n Inicio Simulacao -- Quantum = " + i);

            GerenciadorEscalonador gerenciadorEscalonador = new GerenciadorEscalonador(i);

            gerenciadorEscalonador.carregandoProgramas();
            gerenciadorEscalonador.executaRoundRobin();

            gerenciadorEscalonador.logFinal();

            System.out.println("Fim Simulacao -- Quantum = " + i);
        }
    }
}