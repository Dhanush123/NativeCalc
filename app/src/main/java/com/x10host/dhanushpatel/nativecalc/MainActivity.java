package com.x10host.dhanushpatel.nativecalc;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private native String calcPrint();
    ArrayList<String> jCalcList = new ArrayList<>();
    TextView calcShow;

    static {
        System.loadLibrary("cplusplus11");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        calcShow = (TextView) findViewById(R.id.calcShow);

    }

    public void calcAdd(View v) {
        Button b = (Button) v;
        String buttonText = b.getText().toString();
        jCalcList.add(buttonText);
       // stackAdd(buttonText);
    }

    public void calcSum(View v){
        int jclLength = jCalcList.size();
        String[] jCalcArray = new String[jclLength];

        for(int i=0; i < jclLength;i++){
            jCalcArray[i]=jCalcList.get(i);
        }

        calcShow.setText(calcPrint());
    }





}
