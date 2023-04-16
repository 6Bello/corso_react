import React, { useEffect, useState } from 'react'
import { Text, TextInput, View } from "react-native";
import { Picker } from '@react-native-picker/picker'
import { ratesPage1 } from '../data/currencies';
import CustomButton from '../components/CustomButton';

export default function Converter() {

    const [amount, setAmount] = useState();
    const [convertFrom, setConvertFrom] = useState('EUR');
    const [convertTo, setConvertTo] = useState('THB');
    const [result, setResult] = useState(0);

    const convert = () => {
        const valueFrom = ratesPage1.find( rate => rate.currency === convertFrom)!.value;
        const valueTo = ratesPage1.find(rate => rate.currency === convertTo)!.value;
        setResult((valueTo * amount!) / valueFrom);
    }

    useEffect(() => {
        convert()
    }, [convertFrom,convertTo,convert])
    return (
        <View style={{ padding: 25 }}>
            <Text>Converte from</Text>
            <Picker selectedValue={convertFrom} style={{ height: 5 }}
                onValueChange={(value) => setConvertFrom(value)}>
                {ratesPage1.map((rate) => (
                    <Picker.Item key={rate.currency} label={rate.label} value={rate.currency} />
                ))}
            </Picker>
            <Text>Convert to</Text>
            <Picker selectedValue={convertTo} style={{ height: 5 }}
                onValueChange={(value) => setConvertTo(value)}>
                {ratesPage1.map((rate) => (
                    <Picker.Item key={rate.currency} label={rate.label} value={rate.currency} />
                ))}
            </Picker>
            <Text>amount</Text>
            <TextInput style={{ borderWidth: 2, borderRadius: 5, marginBottom: 5 }}
                value={amount}
                keyboardType='numeric'
                onChangeText={(value: any) =>
                    setAmount(value)} />
            <CustomButton label="Covert" onPress={convert}/>
            <Text>{amount} {ratesPage1.find( rate => rate.currency === convertFrom)!.label} sono {result} {ratesPage1.find(rate => rate.currency === convertTo)!.label}</Text>
        </View>
    )
}