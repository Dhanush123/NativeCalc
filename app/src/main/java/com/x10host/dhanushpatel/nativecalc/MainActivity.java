package com.x10host.dhanushpatel.nativecalc;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private native String calcPrint(String[] jCL,int alLength);
    private native void calcCClear();
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
        Log.i("button pressed: ",buttonText);
        jCalcList.add(buttonText);
        calcShow.setText(calcShow.getText().toString()+buttonText);
    }

    public void calcSum(View v){
        int jclSize = jCalcList.size();
        String[] jCalcArray = new String[jclSize];
        for(int i =0;i<jclSize;i++){
            jCalcArray[i]=jCalcList.get(i);
        }
        calcShow.setText(calcPrint(jCalcArray,jCalcArray.length));
    }

    public void calcClear(View v){
        calcCClear();
        calcShow.setText("");
    }

}
