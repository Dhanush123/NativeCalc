package com.x10host.dhanushpatel.nativecalc;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private native int tipCalc(int x ,double y ,double z);

    static {
        System.loadLibrary("cplusplus11");
    }

    EditText peopleET, billET, tipET;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        peopleET = (EditText) findViewById(R.id.peopleET);
        billET = (EditText) findViewById(R.id.billET);
        tipET = (EditText) findViewById(R.id.tipET);

    }

    public void calculateIndiv(View view){
        int numPeople = Integer.parseInt(peopleET.getText().toString());
        double bill = Integer.parseInt(billET.getText().toString());
        double tip = Integer.parseInt(tipET.getText().toString());

        Log.i("people:"+numPeople,"bill: "+bill+", tip: "+tip);

        double perPerson = Math.round(tipCalc(numPeople,bill,tip) * 100.0)/100.0;

        ((TextView) findViewById(R.id.textView3)).setText(Double.toString(perPerson));
    }






}
