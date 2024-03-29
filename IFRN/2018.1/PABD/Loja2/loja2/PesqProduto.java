/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package loja2;

import javax.swing.JOptionPane;

/**
 *
 * @author 20171024110004
 */
public class PesqProduto extends javax.swing.JFrame {

    /** Creates new form PesqProduto */
    public PesqProduto() {
        initComponents();
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        grupoLocal = new javax.swing.ButtonGroup();
        jLabel1 = new javax.swing.JLabel();
        campoNome = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        cxVarejo = new javax.swing.JCheckBox();
        cxAtacado = new javax.swing.JCheckBox();
        jLabel3 = new javax.swing.JLabel();
        radioTodos = new javax.swing.JRadioButton();
        radioLoja = new javax.swing.JRadioButton();
        radioSite = new javax.swing.JRadioButton();
        jLabel4 = new javax.swing.JLabel();
        comboCategoria = new javax.swing.JComboBox<>();
        botaoPesquisar = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        area = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("Nome:");

        jLabel2.setText("Tipo Venda:");

        cxVarejo.setText("Varejo");

        cxAtacado.setText("Atacado");
        cxAtacado.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cxAtacadoActionPerformed(evt);
            }
        });

        jLabel3.setText("Local Venda:");

        grupoLocal.add(radioTodos);
        radioTodos.setSelected(true);
        radioTodos.setText("Todos");
        radioTodos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                radioTodosActionPerformed(evt);
            }
        });

        grupoLocal.add(radioLoja);
        radioLoja.setText("Loja");

        grupoLocal.add(radioSite);
        radioSite.setText("Site");

        jLabel4.setText("Categoria:");

        comboCategoria.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "---", "Acessórios", "Alimentos", "Bebidas", "Brinquedos", "Calçados", "Comidas", "Diversos", "Higiene", "Maquiagem", "Papelaria", "Roupas" }));

        botaoPesquisar.setText("Pesquisar");
        botaoPesquisar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoPesquisarActionPerformed(evt);
            }
        });

        area.setColumns(20);
        area.setRows(5);
        jScrollPane1.setViewportView(area);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addGap(18, 18, 18)
                        .addComponent(campoNome))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel2)
                                .addGap(18, 18, 18)
                                .addComponent(cxVarejo)
                                .addGap(18, 18, 18)
                                .addComponent(cxAtacado))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel3)
                                .addGap(18, 18, 18)
                                .addComponent(radioTodos)
                                .addGap(18, 18, 18)
                                .addComponent(radioLoja)
                                .addGap(18, 18, 18)
                                .addComponent(radioSite)))
                        .addGap(0, 122, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel4)
                        .addGap(18, 18, 18)
                        .addComponent(comboCategoria, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addComponent(botaoPesquisar))
                    .addComponent(jScrollPane1))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(campoNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(cxVarejo)
                    .addComponent(cxAtacado))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(radioTodos)
                    .addComponent(radioLoja)
                    .addComponent(radioSite))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(comboCategoria, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addComponent(botaoPesquisar)
                .addGap(18, 18, 18)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 133, Short.MAX_VALUE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void cxAtacadoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cxAtacadoActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_cxAtacadoActionPerformed

    private void radioTodosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_radioTodosActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_radioTodosActionPerformed

    private void botaoPesquisarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoPesquisarActionPerformed
        java.sql.Connection conexao = Conexao.getConexao();
        
        try{
            String comando = " SELECT * FROM produto " + " WHERE nome LIKE ? ";
            
            if(cxVarejo.isSelected()){
                comando += " AND varejo = 1 ";
            }
            
            if(cxAtacado.isSelected()){
                comando += " AND atacado = 1 ";
            }
            
            if(radioLoja.isSelected()){
                comando += " AND localv = 'Loja' ";
            }
            
            if(radioSite.isSelected()){
                comando += " AND localv = 'Site' ";
            }
            
            if(comboCategoria.getSelectedIndex() > 0){
                String cat = comboCategoria.getSelectedItem().toString();
                comando += " AND categoria = '" + cat + "' ";                
            }
            
            java.sql.PreparedStatement ps = conexao.prepareStatement(comando);
            
            ps.setString(1, "%" + campoNome.getText() + "%");
            
            java.sql.ResultSet rs = ps.executeQuery();
            
            area.setText(null);
            
            while(rs.next()){
                area.append(rs.getString("codigo")    + "\n");
                area.append(rs.getString("nome")      + "\n");
                area.append(rs.getString("varejo")    + "\n");
                area.append(rs.getString("atacado")   + "\n");
                area.append(rs.getString("localv")    + "\n");
                area.append(rs.getString("categoria") + "\n");
                area.append(rs.getString("preco")     + "\n\n");
            }// while
            
            
        }catch(Exception e){
            JOptionPane.showMessageDialog(null, "ERRO!\n" + e.getMessage());
            e.printStackTrace();
        }// catch
        
        
    }//GEN-LAST:event_botaoPesquisarActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(PesqProduto.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(PesqProduto.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(PesqProduto.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(PesqProduto.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new PesqProduto().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextArea area;
    private javax.swing.JButton botaoPesquisar;
    private javax.swing.JTextField campoNome;
    private javax.swing.JComboBox<String> comboCategoria;
    private javax.swing.JCheckBox cxAtacado;
    private javax.swing.JCheckBox cxVarejo;
    private javax.swing.ButtonGroup grupoLocal;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JRadioButton radioLoja;
    private javax.swing.JRadioButton radioSite;
    private javax.swing.JRadioButton radioTodos;
    // End of variables declaration//GEN-END:variables

}
