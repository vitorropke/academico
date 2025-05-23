package com.example.relate_um_bolido;

import android.os.Bundle;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Locale;

public class EdicaoActivity extends AppCompatActivity {

    EditText entradaLatitude;
    EditText entradaLongitude;
    EditText entradaData;
    EditText entradaHora;
    EditText entradaAzimuteInicial;
    EditText entradaElevacaoInicial;
    EditText entradaAzimuteFinal;
    EditText entradaElevacaoFinal;
    EditText entradaDuracao;
    EditText entradaMagnitude;
    EditText entradaCor;
    CheckBox entradaSom;
    CheckBox entradaRastro;
    CheckBox entradaExplosao;
    EditText entradaObservacoes;
    Button botaoEditarRelato;
    Button botaoApagarRelato;

    Relato relato = new Relato();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edicao);

        entradaLatitude = findViewById(R.id.entrada_latitude_tela_edicao);
        entradaLongitude = findViewById(R.id.entrada_longitude_tela_edicao);
        entradaData = findViewById(R.id.entrada_data_tela_edicao);
        entradaHora = findViewById(R.id.entrada_hora_tela_edicao);
        entradaAzimuteInicial = findViewById(R.id.entrada_azimute_inicial_tela_edicao);
        entradaElevacaoInicial = findViewById(R.id.entrada_elevacao_inicial_tela_edicao);
        entradaAzimuteFinal = findViewById(R.id.entrada_azimute_final_tela_edicao);
        entradaElevacaoFinal = findViewById(R.id.entrada_elevacao_final_tela_edicao);
        entradaDuracao = findViewById(R.id.entrada_duracao_tela_edicao);
        entradaMagnitude = findViewById(R.id.entrada_magnitude_tela_edicao);
        entradaCor = findViewById(R.id.entrada_cor_tela_edicao);
        entradaSom = findViewById(R.id.entrada_som_tela_edicao);
        entradaRastro = findViewById(R.id.entrada_rastro_tela_edicao);
        entradaExplosao = findViewById(R.id.entrada_explosao_tela_edicao);
        entradaObservacoes = findViewById(R.id.entrada_observacoes_tela_edicao);

        botaoEditarRelato = findViewById(R.id.botao_editar_relato);
        botaoApagarRelato = findViewById(R.id.botao_apagar_relato);

        obterDefinirDados();
        botaoEditarRelato.setOnClickListener(view -> {
            String textoEntradaData = entradaData.getText().toString();
            String textoEntradaHora = entradaHora.getText().toString();

            SimpleDateFormat formatoData = new SimpleDateFormat("yyyy/MM/dd", Locale.getDefault());
            SimpleDateFormat formatoHora = new SimpleDateFormat("HH:mm", Locale.getDefault());

            Calendar calendar = Calendar.getInstance();
            try {
                Date dataDate = formatoData.parse(textoEntradaData);
                Date horaDate = formatoHora.parse(textoEntradaHora);

                if ((dataDate != null) && (horaDate != null)) {
                    long milissegundos = dataDate.getTime() + horaDate.getTime();
                    calendar.setTimeInMillis(milissegundos);
                }
            } catch (ParseException e) {
                throw new RuntimeException(e);
            }

            Relato relatoModificado = new Relato();
            relatoModificado.setId(relato.getId());
            relatoModificado.setLatitude(Double.parseDouble(entradaLatitude.getText().toString()));
            relatoModificado.setLongitude(Double.parseDouble(entradaLongitude.getText().toString()));
            relatoModificado.setDataHora(calendar);
            relatoModificado.setAzimuteInicial(Integer.parseInt(entradaAzimuteInicial.getText().toString()));
            relatoModificado.setElevacaoInicial(Integer.parseInt(entradaElevacaoInicial.getText().toString()));
            relatoModificado.setAzimuteFinal(Integer.parseInt(entradaAzimuteFinal.getText().toString()));
            relatoModificado.setElevacaoFinal(Integer.parseInt(entradaElevacaoFinal.getText().toString()));
            relatoModificado.setDuracao(Integer.parseInt(entradaDuracao.getText().toString()));
            relatoModificado.setMagnitude(Integer.parseInt(entradaMagnitude.getText().toString()));
            relatoModificado.setCor(entradaCor.getText().toString());
            relatoModificado.setSom(entradaSom.isChecked());
            relatoModificado.setRastro(entradaRastro.isChecked());
            relatoModificado.setExplosao(entradaExplosao.isChecked());
            relatoModificado.setObservacoes(entradaObservacoes.getText().toString());

            BancoDadosHelper bancoDadosHelper = new BancoDadosHelper(this);
            bancoDadosHelper.editarRelato(relatoModificado, String.valueOf(relatoModificado.getId()));
            finish();
        });

        botaoApagarRelato.setOnClickListener(view -> mensagemConfirmacao());
    }

    public void obterDefinirDados() {
        if (getIntent().hasExtra("id") && getIntent().hasExtra("latitude") &&
                getIntent().hasExtra("longitude") &&
                getIntent().hasExtra("data_hora") &&
                getIntent().hasExtra("azimute_inicial") &&
                getIntent().hasExtra("elevacao_inicial") &&
                getIntent().hasExtra("azimute_final") &&
                getIntent().hasExtra("elevacao_final") &&
                getIntent().hasExtra("duracao") && getIntent().hasExtra("magnitude") &&
                getIntent().hasExtra("cor") && getIntent().hasExtra("som") &&
                getIntent().hasExtra("rastro") && getIntent().hasExtra("explosao") &&
                getIntent().hasExtra("observacoes")) {

            // obtendo dados
            Calendar calendar = Calendar.getInstance();
            calendar.setTimeInMillis(getIntent().getLongExtra("data_hora", 0));

            relato.setId(getIntent().getIntExtra("id", 0));
            relato.setLatitude(getIntent().getDoubleExtra("latitude", 0));
            relato.setLongitude(getIntent().getDoubleExtra("longitude", 0));
            relato.setDataHora(calendar);
            relato.setAzimuteInicial(getIntent().getIntExtra("azimute_inicial", 0));
            relato.setElevacaoInicial(getIntent().getIntExtra("elevacao_inicial", 0));
            relato.setAzimuteFinal(getIntent().getIntExtra("azimute_final", 0));
            relato.setElevacaoFinal(getIntent().getIntExtra("elevacao_final", 0));
            relato.setDuracao(getIntent().getIntExtra("duracao", 0));
            relato.setMagnitude(getIntent().getIntExtra("magnitude", 0));
            relato.setCor(getIntent().getStringExtra("cor"));
            relato.setSom(getIntent().getBooleanExtra("som", false));
            relato.setRastro(getIntent().getBooleanExtra("rastro", false));
            relato.setExplosao(getIntent().getBooleanExtra("explosao", false));
            relato.setObservacoes(getIntent().getStringExtra("observacoes"));

            // preenchendo dados existentes
            SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy/MM/dd", Locale.getDefault());
            String data = simpleDateFormat.format(calendar.getTime());
            simpleDateFormat.applyPattern("HH:mm");
            String hora = simpleDateFormat.format(calendar.getTime());

            entradaLatitude.setText(String.valueOf(relato.getLatitude()));
            entradaLongitude.setText(String.valueOf(relato.getLongitude()));
            entradaData.setText(data);
            entradaHora.setText(hora);
            entradaAzimuteInicial.setText(String.valueOf(relato.getAzimuteInicial()));
            entradaElevacaoInicial.setText(String.valueOf(relato.getElevacaoInicial()));
            entradaAzimuteFinal.setText(String.valueOf(relato.getAzimuteFinal()));
            entradaElevacaoFinal.setText(String.valueOf(relato.getElevacaoFinal()));
            entradaDuracao.setText(String.valueOf(relato.getDuracao()));
            entradaMagnitude.setText(String.valueOf(relato.getMagnitude()));
            entradaCor.setText(relato.getCor());
            entradaSom.setChecked(relato.hasSom());
            entradaRastro.setChecked(relato.hasRastro());
            entradaExplosao.setChecked(relato.hasExplosao());
            entradaObservacoes.setText(relato.getObservacoes());
        } else {
            Toast.makeText(this, "Sem dados.", Toast.LENGTH_SHORT).show();
        }
    }

    public void mensagemConfirmacao() {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("Apagar relato " + relato.getId() + "?");
        builder.setMessage("Deseja mesmo apagar este relato?");
        builder.setPositiveButton("Sim", (dialogInterface, i) -> {
            BancoDadosHelper bancoDadosHelper = new BancoDadosHelper(EdicaoActivity.this);
            bancoDadosHelper.apagarRelato(String.valueOf(relato.getId()));
            finish();
        });
        builder.setNegativeButton("Nao", (dialogInterface, i) -> {
        });
        builder.create().show();
    }

}
