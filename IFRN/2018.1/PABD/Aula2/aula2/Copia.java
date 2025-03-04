/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package aula2;

/**
 *
 * @author 20171024110004
 */
public class Copia extends javax.swing.JFrame {

    /**
     * Creates new form Copia
     */
    public Copia() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        campoOriginal = new javax.swing.JTextField();
        botaoCopiar = new javax.swing.JButton();
        campoCopia = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Copiador v1.0");
        setAlwaysOnTop(true);

        campoOriginal.setBackground(new java.awt.Color(255, 255, 153));
        campoOriginal.setFont(new java.awt.Font("Courier New", 1, 14)); // NOI18N
        campoOriginal.setForeground(new java.awt.Color(51, 51, 255));
        campoOriginal.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        campoOriginal.setToolTipText("Digite o texto original aqui.");
        campoOriginal.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                campoOriginalActionPerformed(evt);
            }
        });

        botaoCopiar.setText("vv COPIAR vv");
        botaoCopiar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoCopiarActionPerformed(evt);
            }
        });

        campoCopia.setBackground(new java.awt.Color(153, 255, 153));
        campoCopia.setEditable(false);
        campoCopia.setForeground(new java.awt.Color(255, 0, 51));
        campoCopia.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        campoCopia.setText("[a cópia aparece aqui]");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(campoOriginal)
                    .addComponent(botaoCopiar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(campoCopia, javax.swing.GroupLayout.DEFAULT_SIZE, 254, Short.MAX_VALUE))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(campoOriginal, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(botaoCopiar)
                .addGap(18, 18, 18)
                .addComponent(campoCopia, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void campoOriginalActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_campoOriginalActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_campoOriginalActionPerformed

    private void botaoCopiarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoCopiarActionPerformed
        // capturar o texto do campoOriginal
        String texto = campoOriginal.getText();
        
        // colocar o texto dentro do campo
        campoCopia.setText(texto);
        
    }//GEN-LAST:event_botaoCopiarActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /*
         * Set the Nimbus look and feel
         */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /*
         * If Nimbus (introduced in Java SE 6) is not available, stay with the
         * default look and feel. For details see
         * http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Copia.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Copia.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Copia.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Copia.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /*
         * Create and display the form
         */
        java.awt.EventQueue.invokeLater(new Runnable() {

            public void run() {
                new Copia().setVisible(true);
            }
        });
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton botaoCopiar;
    private javax.swing.JTextField campoCopia;
    private javax.swing.JTextField campoOriginal;
    // End of variables declaration//GEN-END:variables
}
