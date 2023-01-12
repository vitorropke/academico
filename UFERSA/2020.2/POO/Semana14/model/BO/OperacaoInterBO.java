package br.edu.ufersa.ropke.locadoramaven.model.BO;

import java.io.File;
import java.util.ArrayList;

public interface OperacaoInterBO<VO> {
	public void cadastrar(VO entidade, File arquivo);

	public void alterar(VO entidade, File arquivo);

	public void deletar(VO entidade, File arquivo);

	public void pesquisar(File arquivo);

	public VO pesquisar(VO entidade, File arquivo);

	public ArrayList<VO> listar(File arquivo);
}
