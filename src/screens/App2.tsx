import React, { useEffect, useState } from 'react';
import styles from './style/style';
import { Button, StyleSheet, Text, TextInput, View } from 'react-native';
import CustomButton from './components/CustomButton';

const cliccato = () => console.log('non toccarmi');

function App2() {

    const [numero1, setNumero1] = useState(0);
    const [numero2, setNumero2] = useState(0);
    const [sum, setSum] = useState();

    const somma = () => {
        setSum(numero1 + numero2);
    }


    return (
        <View style={styles.container}>
            <Text style={styles.titolo} onPress={cliccato}>
                MAIN TITLE
            </Text>
            <TextInput style={styles.input} keyboardType='number-pad' onChangeText={text => setNumero1(Number(text))} />
            <Text>{numero1}</Text>
            <TextInput style={styles.input} keyboardType='number-pad' onChangeText={text => setNumero2(Number(text))} />
            <Text>{numero2}</Text>
            <Text>SOMMA: {sum}</Text>            
            <CustomButton onPress={somma} label="Bottone Nativo" bgColor="#666">{/*uso gli apici quando devo passare una stringa mentre uso le parentesi graffe quando passo js */}</CustomButton> 

        </View>
    );
}

export default App2